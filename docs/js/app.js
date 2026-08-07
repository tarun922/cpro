/* ---------- boot ---------- */
async function boot(){
  Render.init();
  Render.setStatus('connecting…', '');

  const cached = GitHub.loadCache();
  if(cached && cached.length){
    Render.setFiles(cached);
    Render.renderAll();
    Render.setStatus('cached', '');
  } else {
    Render.showLoading();
  }

  try{
    const fresh = await GitHub.fetchRepoFiles();
    if(fresh.length){
      GitHub.saveCache(fresh);
      Render.setFiles(fresh);
      Render.renderAll();
      Render.setStatus('live · ' + fresh.length + ' files', 'live');
    } else {
      Render.setStatus('no .c files found', 'err');
    }
  }catch(e){
    if(!cached){
      Render.showEmptyOffline();
    }
    Render.setStatus('offline · showing cached', 'err');
  }
}

/* ---------- theme toggle ---------- */
document.getElementById('modeToggle').addEventListener('click', () => {
  document.body.classList.toggle('light');
  document.getElementById('modeToggle').textContent = document.body.classList.contains('light') ? '☀' : '☾';
  try{ localStorage.setItem('cpro-theme', document.body.classList.contains('light') ? 'light' : 'dark'); }catch(e){}
});
(function restoreTheme(){
  try{
    if(localStorage.getItem('cpro-theme') === 'light'){
      document.body.classList.add('light');
      document.getElementById('modeToggle').textContent = '☀';
    }
  }catch(e){}
})();

/* ---------- search ---------- */
const searchInput = document.getElementById('searchInput');
if(searchInput){
  searchInput.addEventListener('input', () => Render.setQuery(searchInput.value));
}

/* ---------- service worker ---------- */
if('serviceWorker' in navigator){
  window.addEventListener('load', () => navigator.serviceWorker.register('sw.js').catch(() => {}));
}

boot();
