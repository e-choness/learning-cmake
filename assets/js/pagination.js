// Shared pagination helper — used by french-cards.js, tcf-drills.js, blog-list.js
window.Pagination = {
  PAGE_SIZE: 12,

  // Returns an array of page numbers (1-based) interspersed with '...' strings.
  buildPages(current, total) {
    if (total <= 7) {
      return Array.from({ length: total }, (_, i) => i + 1);
    }
    const set = new Set(
      [1, total, current, current - 1, current + 1].filter(p => p >= 1 && p <= total)
    );
    const sorted = [...set].sort((a, b) => a - b);
    const result = [];
    let prev = 0;
    for (const p of sorted) {
      if (p - prev > 1) result.push('...');
      result.push(p);
      prev = p;
    }
    return result;
  },

  // Renders pagination controls into `container`.
  // container: DOM element with data-i18n-*-en / data-i18n-*-fr attributes
  // onPageChange: function(newPage) called when user clicks a control
  render(container, currentPage, totalPages, onPageChange) {
    container.innerHTML = '';
    if (totalPages <= 1) return;

    const lang = document.documentElement.getAttribute('data-lang') || 'en';
    const s = lang === 'fr' ? 'Fr' : 'En';
    const labels = {
      first: container.dataset['i18nFirst' + s] || 'First page',
      prev:  container.dataset['i18nPrev'  + s] || 'Previous page',
      next:  container.dataset['i18nNext'  + s] || 'Next page',
      last:  container.dataset['i18nLast'  + s] || 'Last page',
      page:  container.dataset['i18nPage'  + s] || 'Page',
    };

    const nav = document.createElement('nav');
    nav.className = 'pagination-nav';
    nav.setAttribute('aria-label', 'Pagination');

    const mk = (text, ariaLabel, disabled, onClick) => {
      const btn = document.createElement('button');
      btn.className = 'pagination-btn';
      btn.textContent = text;
      btn.setAttribute('aria-label', ariaLabel);
      if (disabled) {
        btn.disabled = true;
        btn.setAttribute('aria-disabled', 'true');
      } else {
        btn.addEventListener('click', onClick);
      }
      return btn;
    };

    nav.appendChild(mk('<<', labels.first, currentPage === 1,          () => onPageChange(1)));
    nav.appendChild(mk('<',  labels.prev,  currentPage === 1,          () => onPageChange(currentPage - 1)));

    this.buildPages(currentPage, totalPages).forEach(p => {
      if (p === '...') {
        const el = document.createElement('span');
        el.className = 'pagination-ellipsis';
        el.textContent = '…';
        el.setAttribute('aria-hidden', 'true');
        nav.appendChild(el);
      } else {
        const btn = mk(String(p), `${labels.page} ${p}`, false, () => onPageChange(p));
        if (p === currentPage) {
          btn.classList.add('active');
          btn.setAttribute('aria-current', 'page');
        }
        nav.appendChild(btn);
      }
    });

    nav.appendChild(mk('>',  labels.next, currentPage === totalPages,  () => onPageChange(currentPage + 1)));
    nav.appendChild(mk('>>', labels.last, currentPage === totalPages,  () => onPageChange(totalPages)));

    container.appendChild(nav);
  }
};
