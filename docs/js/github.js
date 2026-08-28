/* ---------- fetch .c files from the linked github repo (recursive, folder-aware) ---------- */
const GitHub = (() => {
  const ROOT_KEY = '_root';

  function titleCase(str){
    return str.replace(/[_-]/g, ' ').replace(/\b\w/g, c => c.toUpperCase());
  }

  async function fetchRepoFiles(){
    // 1. figure out the default branch
    const repoRes = await fetch(`https://api.github.com/repos/${CONFIG.REPO_OWNER}/${CONFIG.REPO_NAME}`);
    if(!repoRes.ok) throw new Error('repo failed: ' + repoRes.status);
    const repoInfo = await repoRes.json();
    const branch = repoInfo.default_branch || 'main';

    // 2. walk the whole tree in one call (recursive), so nested folders are included
    const treeRes = await fetch(`https://api.github.com/repos/${CONFIG.REPO_OWNER}/${CONFIG.REPO_NAME}/git/trees/${branch}?recursive=1`);
    if(!treeRes.ok) throw new Error('tree failed: ' + treeRes.status);
    const treeData = await treeRes.json();
    const tree = treeData.tree || [];

    const cEntries = tree.filter(e => e.type === 'blob' && e.path.endsWith('.c'));

    // Makefiles aren't shown as their own sidebar entries — they're fetched up front and
    // attached to whichever .c file lives in the same directory, keyed by that directory path.
    const makefileEntries = tree.filter(e => e.type === 'blob' && e.path.split('/').pop() === 'Makefile');
    const makefileByDir = {};
    for(const entry of makefileEntries){
      const dir = entry.path.split('/').slice(0, -1).join('/');
      const rawUrl = `https://raw.githubusercontent.com/${CONFIG.REPO_OWNER}/${CONFIG.REPO_NAME}/${branch}/${entry.path}`;
      const r = await fetch(rawUrl);
      makefileByDir[dir] = await r.text();
    }

    // sort: grouped by top-level folder (alphabetical), root-level files last, files alphabetical within a folder
    cEntries.sort((a, b) => {
      const aParts = a.path.split('/'), bParts = b.path.split('/');
      const aFolder = aParts.length > 1 ? aParts[0] : ROOT_KEY;
      const bFolder = bParts.length > 1 ? bParts[0] : ROOT_KEY;
      if(aFolder !== bFolder){
        if(aFolder === ROOT_KEY) return 1;
        if(bFolder === ROOT_KEY) return -1;
        return aFolder.localeCompare(bFolder);
      }
      return a.path.localeCompare(b.path);
    });

    const results = [];
    for(const entry of cEntries){
      const path = entry.path;
      const parts = path.split('/');
      const fileName = parts[parts.length - 1];
      const folder = parts.length > 1 ? parts[0] : ROOT_KEY;
      const dir = parts.slice(0, -1).join('/');

      // chapter-style: folder/chapter/main.c (depth 3+). Every chapter's file is literally
      // called main.c, so we name the entry after the chapter folder instead of the filename,
      // otherwise every item in a course folder would show up as "Main".
      const isChapterStyle = parts.length >= 3;
      const chapterName = isChapterStyle ? parts[parts.length - 2] : null;

      const rawUrl = `https://raw.githubusercontent.com/${CONFIG.REPO_OWNER}/${CONFIG.REPO_NAME}/${branch}/${path}`;
      const r = await fetch(rawUrl);
      const code = await r.text();

      results.push({
        id: path,
        file: fileName,
        path,
        folder,
        folderLabel: folder === ROOT_KEY ? 'misc' : titleCase(folder),
                   name: isChapterStyle ? titleCase(chapterName) : titleCase(fileName.replace(/\.c$/, '')),
                   code,
                   notes: NotesParser.parse(code),
                   makefile: makefileByDir[dir] || null,
      });
    }
    return results;
  }

  function loadCache(){
    try{
      const cached = localStorage.getItem(CONFIG.CACHE_KEY);
      return cached ? JSON.parse(cached) : null;
    }catch(e){ return null; }
  }

  function saveCache(files){
    try{ localStorage.setItem(CONFIG.CACHE_KEY, JSON.stringify(files)); }catch(e){}
  }

  return { fetchRepoFiles, loadCache, saveCache };
})();
