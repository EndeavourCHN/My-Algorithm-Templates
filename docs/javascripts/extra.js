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

  function syncGiscusTheme() {
    const frame = document.querySelector("iframe.giscus-frame");
    if (!frame) return;

    const theme = document.body.getAttribute("data-md-color-scheme") === "slate" ? "dark" : "light";
    frame.contentWindow.postMessage(
      { giscus: { setConfig: { theme } } },
      "https://giscus.app"
    );
  }

  document.addEventListener("change", event => {
    if (event.target && event.target.matches("[name='__palette']")) {
      window.setTimeout(syncGiscusTheme, 0);
    }
  });
})();
