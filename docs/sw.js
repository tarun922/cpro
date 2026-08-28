const CACHE = 'cpro-notes-shell-v4';
const SHELL = [
  './',
'./index.html',
'./manifest.json',
'./icon-192.png',
'./icon-512.png',
'./css/tokens.css',
'./css/layout.css',
'./css/components.css',
'./js/config.js',
'./js/highlight.js',
'./js/notesParser.js',
'./js/github.js',
'./js/render.js',
'./js/app.js',
];

self.addEventListener('install', e => {
  e.waitUntil(caches.open(CACHE).then(c => c.addAll(SHELL)));
  self.skipWaiting();
});

self.addEventListener('activate', e => {
  e.waitUntil(
    caches.keys().then(keys => Promise.all(keys.filter(k => k !== CACHE).map(k => caches.delete(k))))
  );
  self.clients.claim();
});

// app shell: cache-first. github api calls: network-only (handled by fetch in app.js, not intercepted here).
self.addEventListener('fetch', e => {
  const url = new URL(e.request.url);
  if(url.origin !== location.origin) return; // let github api/raw calls pass straight through
  e.respondWith(
    caches.match(e.request).then(cached => cached || fetch(e.request))
  );
});
