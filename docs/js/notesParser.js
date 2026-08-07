/* ---------- parse leading // comments into annotated notes ---------- */
const NotesParser = (() => {
  function guessType(text){
    if(/\bdouble\b/.test(text)) return 'double';
    if(/\bfloat\b/.test(text)) return 'float';
    if(/\bbool\b/.test(text)) return 'bool';
    if(/\bchar\s+\w+\s*\[/.test(text)) return 'string';
    if(/\bchar\b/.test(text)) return 'char';
    if(/%s/.test(text)) return 'string';
    return 'int';
  }

  function parse(code){
    const lines = code.split('\n');
    const notes = [];
    let i = 0;
    while(i < lines.length){
      const trimmed = lines[i].trim();
      if(trimmed.startsWith('//')){
        const commentLines = [];
        while(i < lines.length && lines[i].trim().startsWith('//')){
          commentLines.push(lines[i].trim().replace(/^\/\/\s?/, ''));
          i++;
        }
        while(i < lines.length && lines[i].trim() === '') i++;

        const codeStart = i + 1; // 1-indexed
        let codeEnd = codeStart;
        while(i < lines.length && lines[i].trim() !== '' && !lines[i].trim().startsWith('//')){
          codeEnd = i + 1;
          i++;
        }

        if(commentLines.length && codeEnd >= codeStart){
          const bodyText = commentLines.join(' ');
          notes.push({
            lines: [codeStart, codeEnd],
            type: guessType(bodyText + ' ' + lines.slice(codeStart - 1, codeEnd).join(' ')),
            title: commentLines[0].slice(0, 48),
            body: Highlight.escapeHtml(bodyText),
          });
        }
      } else {
        i++;
      }
    }
    return notes;
  }

  return { parse };
})();
