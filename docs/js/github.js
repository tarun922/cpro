/* ---------- fetch .c files from the linked github repo ---------- */
const GitHub = (() => {
  async function fetchRepoFiles(){
    const listUrl = `https://api.github.com/repos/${CONFIG.REPO_OWNER}/${CONFIG.REPO_NAME}/contents/`;
    const res = await fetch(listUrl);
    if(!res.ok) throw new Error('list failed: ' + res.status);
    const list = await res.json();
    const cFiles = list.filter(f => f.type === 'file' && f.name.endsWith('.c'));

    const results = [];
    for(const f of cFiles){
      const r = await fetch(f.download_url);
      const code = await r.text();
      results.push({
        id: f.name.replace(/\.c$/, ''),
        file: f.name,
        name: f.name.replace(/\.c$/, '').replace(/_/g, ' ').replace(/\b\w/g, c => c.toUpperCase()),
        code,
        notes: NotesParser.parse(code),
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
