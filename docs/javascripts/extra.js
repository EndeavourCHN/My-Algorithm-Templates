(() => {
  const desktopQuery = window.matchMedia("(min-width: 76.25em)");

  function syncSidebarState() {
    const drawer = document.getElementById("__drawer");
    if (!drawer) return;

    if (desktopQuery.matches) {
      document.body.classList.toggle("oi-sidebar-collapsed", drawer.checked);
    } else {
      document.body.classList.remove("oi-sidebar-collapsed");
    }
  }

  document.addEventListener("DOMContentLoaded", () => {
    const drawer = document.getElementById("__drawer");
    if (!drawer) return;

    drawer.addEventListener("change", syncSidebarState);
    desktopQuery.addEventListener("change", syncSidebarState);
    syncSidebarState();
  });
})();
