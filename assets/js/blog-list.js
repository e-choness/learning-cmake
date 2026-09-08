// Blog list — order toggle (newest/oldest first) over month sections
(function () {
  const ORDER_KEY = 'tcf-journey-blog-order';

  document.addEventListener('DOMContentLoaded', () => {
    const list = document.getElementById('posts-list');
    const btn = document.getElementById('blog-sort-toggle');
    const paginationEl = document.getElementById('blog-pagination');
    if (!list || !btn) return;

    let order = localStorage.getItem(ORDER_KEY);
    if (order !== 'asc' && order !== 'desc') order = 'desc';
    let currentPage = 1;

    function relabel() {
      const lang = document.documentElement.getAttribute('data-lang') || 'en';
      const key = (order === 'asc' ? 'oldest' : 'newest') + (lang === 'fr' ? 'Fr' : 'En');
      const label = btn.querySelector('.sort-label');
      const arrow = btn.querySelector('.sort-arrow');
      if (label) label.textContent = btn.dataset[key] || '';
      if (arrow) arrow.textContent = order === 'asc' ? '↑' : '↓';
      btn.dataset.order = order;
      btn.setAttribute('aria-label', label ? label.textContent : '');
    }

    function paginate() {
      const posts = Array.from(list.querySelectorAll('.post-preview'));
      const total = posts.length;
      const totalPages = Math.max(1, Math.ceil(total / Pagination.PAGE_SIZE));
      if (currentPage > totalPages) currentPage = Math.max(1, totalPages);
      const start = (currentPage - 1) * Pagination.PAGE_SIZE;
      const end = start + Pagination.PAGE_SIZE;

      posts.forEach((post, i) => {
        post.classList.toggle('page-hidden', i < start || i >= end);
      });

      // Hide month sections that have no visible posts on this page
      list.querySelectorAll('.post-month').forEach(section => {
        const any = Array.from(section.querySelectorAll('.post-preview'))
          .some(p => !p.classList.contains('page-hidden'));
        section.style.display = any ? '' : 'none';
      });

      if (paginationEl) {
        Pagination.render(paginationEl, currentPage, totalPages, page => {
          currentPage = page;
          paginate();
          paginationEl.scrollIntoView({ behavior: 'smooth', block: 'nearest' });
        });
      }
    }

    function apply() {
      const dir = order === 'asc' ? 1 : -1;
      const groups = Array.from(list.querySelectorAll('.post-month'));
      groups.sort((a, b) => dir * a.dataset.month.localeCompare(b.dataset.month));
      groups.forEach(group => {
        const rows = Array.from(group.querySelectorAll('.post-preview'));
        rows.sort((a, b) => dir * a.dataset.date.localeCompare(b.dataset.date));
        group.append(...rows);          // label stays first, rows re-appended in order
      });
      list.append(...groups);
      relabel();
      paginate();
    }

    btn.addEventListener('click', () => {
      order = order === 'asc' ? 'desc' : 'asc';
      try { localStorage.setItem(ORDER_KEY, order); } catch (e) {}
      currentPage = 1;
      apply();
    });

    document.addEventListener('langchange', () => {
      relabel();
      if (paginationEl) {
        const posts = Array.from(list.querySelectorAll('.post-preview'));
        const totalPages = Math.max(1, Math.ceil(posts.length / Pagination.PAGE_SIZE));
        Pagination.render(paginationEl, currentPage, totalPages, page => {
          currentPage = page;
          paginate();
          paginationEl.scrollIntoView({ behavior: 'smooth', block: 'nearest' });
        });
      }
    });

    apply();
  });
})();
