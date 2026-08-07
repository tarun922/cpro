/* ---------- tiny C syntax highlighter ---------- */
const Highlight = (() => {
  const TOKEN_RE = /(#include|#define)|("(?:[^"\\]|\\.)*")|('(?:[^'\\]|\\.)*')|(\b\d+\.?\d*f?\b)|(\b(?:int|float|double|char|bool|void|return|if|else|for|while|true|false)\b)|(\bprintf|scanf|fgets|getchar|main\b)/g;

  function escapeHtml(s){
    return s.replace(/&/g,'&amp;').replace(/</g,'&lt;').replace(/>/g,'&gt;');
  }

  function line(rawLine){
    const cIdx = rawLine.indexOf('//');
    const code = cIdx >= 0 ? rawLine.slice(0, cIdx) : rawLine;
    const comment = cIdx >= 0 ? rawLine.slice(cIdx) : '';

    let html = '';
    let last = 0;
    let m;
    TOKEN_RE.lastIndex = 0;
    while((m = TOKEN_RE.exec(code)) !== null){
      html += escapeHtml(code.slice(last, m.index));
      const tok = m[0];
      if(m[1]) html += `<span class="tk-kw">${escapeHtml(tok)}</span>`;
      else if(m[2] || m[3]) html += `<span class="tk-str">${escapeHtml(tok)}</span>`;
      else if(m[4]) html += `<span class="tk-num">${escapeHtml(tok)}</span>`;
      else if(m[5]) html += `<span class="tk-type">${escapeHtml(tok)}</span>`;
      else if(m[6]) html += `<span class="tk-fn">${escapeHtml(tok)}</span>`;
      last = TOKEN_RE.lastIndex;
    }
    html += escapeHtml(code.slice(last));
    if(comment) html += `<span class="tk-cmt">${escapeHtml(comment)}</span>`;
    return html || '&nbsp;';
  }

  return { line, escapeHtml };
})();
