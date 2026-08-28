/* ---------- rendering ---------- */
const Render = (() => {
  let els = {};
  let state = { files: [], groups: [], current: null, query: '', activeFolder: null, collapsed: new Set(), view: 'code' };

  function init(){
    els = {
      sidebar: document.getElementById('sidebar'),
                folderTabs: document.getElementById('folderTabs'),
                tabs: document.getElementById('tabs'),
                pageDesc: document.getElementById('pageDesc'),
                lineCount: document.getElementById('lineCount'),
                content: document.getElementById('content'),
                status: document.getElementById('status'),
                search: document.getElementById('searchInput'),
    };
  }

  function buildGroups(files){
    const map = new Map();
    files.forEach(f => {
      if(!map.has(f.folder)) map.set(f.folder, { key: f.folder, label: f.folderLabel, files: [] });
      map.get(f.folder).files.push(f);
    });
    return Array.from(map.values());
  }

  function setStatus(text, cls){
    els.status.innerHTML = `<span class="pulse"></span><span>${text}</span>`;
    els.status.className = 'status' + (cls ? ' ' + cls : '');
  }

  function filteredFiles(){
    const q = state.query.trim().toLowerCase();
    if(!q) return state.files;
    return state.files.filter(f => f.name.toLowerCase().includes(q) || f.file.toLowerCase().includes(q));
  }

  function selectFile(f){
    state.current = f;
    state.activeFolder = f.folder;
    state.view = 'code';
    state.collapsed.delete(f.folder);
    renderAll();
  }

  function selectFolder(key){
    state.activeFolder = key;
    state.collapsed.delete(key);
    const group = state.groups.find(g => g.key === key);
    if(group && group.files.length && (!state.current || state.current.folder !== key)){
      state.current = group.files[0];
      state.view = 'code';
      renderAll();
    } else {
      renderNav();
    }
  }

  function toggleGroup(key){
    if(state.collapsed.has(key)) state.collapsed.delete(key); else state.collapsed.add(key);
    renderNav();
  }

  function itemHtml(f){
    return `
    <div class="sidebar-item${state.current && state.current.id === f.id ? ' active' : ''}" data-id="${f.id}">
    <span class="dot"></span>${f.name}
    </div>
    `;
  }

  function tabHtml(f){
    return `<button class="tab${state.current && state.current.id === f.id ? ' active' : ''}" data-id="${f.id}">${f.name}</button>`;
  }

  function groupHtml(g){
    return `
    <div class="sidebar-group${state.collapsed.has(g.key) ? ' collapsed' : ''}">
    <button class="sidebar-group-header" data-folder="${g.key}">
    <span class="chev">▸</span>
    <span class="folder-name">${g.label}</span>
    <span class="folder-count">${g.files.length}</span>
    </button>
    <div class="sidebar-group-body">
    ${g.files.map(itemHtml).join('')}
    </div>
    </div>
    `;
  }

  function folderPillHtml(g){
    return `
    <button class="folder-pill${state.activeFolder === g.key ? ' active' : ''}" data-folder="${g.key}">
    <span class="fname">${g.label}</span><span class="fcount">${g.files.length}</span>
    </button>
    `;
  }

  function wireFileClicks(container){
    container.querySelectorAll('[data-id]').forEach(el => {
      el.addEventListener('click', () => {
        const f = state.files.find(x => x.id === el.dataset.id);
        if(f) selectFile(f);
      });
    });
  }

  function renderNav(){
    const q = state.query.trim().toLowerCase();
    const searching = !!q;
    const list = filteredFiles();

    /* ---- sidebar (desktop) ---- */
    if(searching){
      els.sidebar.innerHTML = `<div class="sidebar-label">matches · ${list.length}</div>` +
      (list.map(itemHtml).join('') || `<div class="sidebar-label">no matches</div>`);
    } else {
      els.sidebar.innerHTML = state.groups.map(groupHtml).join('') || `<div class="sidebar-label">no files yet</div>`;
    }
    wireFileClicks(els.sidebar);
    els.sidebar.querySelectorAll('.sidebar-group-header').forEach(el => {
      el.addEventListener('click', () => toggleGroup(el.dataset.folder));
    });

    /* ---- mobile: folder pills + file pills ---- */
    if(searching){
      els.folderTabs.classList.add('hidden');
      els.folderTabs.innerHTML = '';
      els.tabs.innerHTML = list.map(tabHtml).join('');
    } else {
      els.folderTabs.classList.remove('hidden');
      els.folderTabs.innerHTML = state.groups.map(folderPillHtml).join('');
      els.folderTabs.querySelectorAll('.folder-pill').forEach(el => {
        el.addEventListener('click', () => selectFolder(el.dataset.folder));
      });

      const activeGroup = state.groups.find(g => g.key === state.activeFolder) || state.groups[0];
      els.tabs.innerHTML = activeGroup ? activeGroup.files.map(tabHtml).join('') : '';
    }
    wireFileClicks(els.tabs);
  }

  function renderPage(){
    const current = state.current;
    if(!current){
      els.pageDesc.textContent = '';
      els.lineCount.textContent = '';
      return;
    }

    const showingMakefile = state.view === 'makefile' && current.makefile;
    const bodyText = showingMakefile ? current.makefile : current.code;
    const displayName = showingMakefile ? 'Makefile' : current.file;

    els.pageDesc.textContent = current.file;
    const lines = bodyText.split('\n');
    els.lineCount.textContent = showingMakefile
    ? lines.length + ' lines'
    : lines.length + ' lines · ' + current.notes.length + ' notes';

    const codeHtml = lines.map((ln, idx) => {
      const n = idx + 1;
      return `<div class="code-line" data-line="${n}"><span class="ln">${n}</span><span class="src">${Highlight.line(ln)}</span></div>`;
    }).join('');

    const toggleHtml = current.makefile ? `
    <div class="code-toggle">
    <button class="toggle-btn${!showingMakefile ? ' active' : ''}" id="viewCodeBtn">${current.file}</button>
    <button class="toggle-btn${showingMakefile ? ' active' : ''}" id="viewMakeBtn">Makefile</button>
    </div>
    ` : '';

    const notesHtml = showingMakefile
    ? `<div class="empty" style="padding:20px 4px;">this is the build recipe for ${current.file} — switch back to ${current.file} to see annotated notes.</div>`
    : (current.notes.map((n, idx) => `
    <div class="note" data-idx="${idx}" data-lines="${n.lines[0]}-${n.lines[1]}">
    <div class="note-top">
    <span class="note-title">${n.title}</span>
    <span class="badge ${n.type}">L${n.lines[0]}-${n.lines[1]}</span>
    </div>
    <div class="note-body">${n.body}</div>
    </div>
    `).join('') || `<div class="empty" style="padding:20px 4px;">no annotated comments in this file yet.</div>`);

    els.content.innerHTML = `
    <div class="content-grid">
    <div class="code-card">
    <div class="code-head">
    <div class="dot r"></div><div class="dot y"></div><div class="dot g"></div>
    <span class="fname">${displayName}</span>
    ${toggleHtml}
    <button class="copybtn" id="copyBtn">copy</button>
    </div>
    <div class="code-body" id="codeBody">${codeHtml}</div>
    </div>
    <div class="notes-col">
    <div class="rail-label">what's happening</div>
    ${notesHtml}
    </div>
    </div>
    `;

    wireNoteInteractions(current, bodyText, showingMakefile);
  }

  function wireNoteInteractions(current, bodyText, showingMakefile){
    const codeBody = document.getElementById('codeBody');
    const copyBtn = document.getElementById('copyBtn');
    const viewCodeBtn = document.getElementById('viewCodeBtn');
    const viewMakeBtn = document.getElementById('viewMakeBtn');

    if(copyBtn){
      copyBtn.addEventListener('click', async () => {
        try{
          await navigator.clipboard.writeText(bodyText);
          copyBtn.textContent = 'copied';
          copyBtn.classList.add('copied');
          setTimeout(() => { copyBtn.textContent = 'copy'; copyBtn.classList.remove('copied'); }, 1200);
        }catch(e){}
      });
    }

    if(viewCodeBtn){
      viewCodeBtn.addEventListener('click', () => { state.view = 'code'; renderPage(); });
    }
    if(viewMakeBtn){
      viewMakeBtn.addEventListener('click', () => { state.view = 'makefile'; renderPage(); });
    }

    if(showingMakefile) return; // no line-note highlighting for the Makefile view

    els.content.querySelectorAll('.note').forEach(el => {
      el.addEventListener('click', () => {
        els.content.querySelectorAll('.note').forEach(n => n.classList.remove('active'));
        el.classList.add('active');

        const [start, end] = el.dataset.lines.split('-').map(Number);
        codeBody.querySelectorAll('.code-line').forEach(c => c.classList.remove('hl'));
        let target = null;
        for(let n = start; n <= end; n++){
          const l = codeBody.querySelector(`.code-line[data-line="${n}"]`);
          if(l){ l.classList.add('hl'); if(!target) target = l; }
        }
        if(target) target.scrollIntoView({ block: 'center', behavior: 'smooth' });
      });
    });
  }

  function renderAll(){
    renderNav();
    renderPage();
  }

  function showLoading(){
    els.content.innerHTML = `<div class="empty"><div class="spin"></div><div>pulling files from github…</div></div>`;
  }

  function showEmptyOffline(){
    els.content.innerHTML = `<div class="empty">couldn't reach github and no cached copy yet.<br>check your connection.<div class="hint">pull to retry once you're back online</div></div>`;
  }

  function setFiles(files){
    state.files = files;
    state.groups = buildGroups(files);
    if(!state.current || !files.find(f => f.id === state.current.id)){
      state.current = files[0] || null;
      state.view = 'code';
    }
    if(!state.activeFolder || !state.groups.find(g => g.key === state.activeFolder)){
      state.activeFolder = state.current ? state.current.folder : (state.groups[0] ? state.groups[0].key : null);
    }
  }

  function setQuery(q){
    state.query = q;
    renderNav();
  }

  return { init, setStatus, setFiles, renderAll, showLoading, showEmptyOffline, setQuery };
})();
