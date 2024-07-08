document.addEventListener("DOMContentLoaded", function() {
    const buttons = document.querySelectorAll('.x');
    const dropdownLinks = document.querySelectorAll('.dropdown a');

    // Function to remove active class from all buttons and links
    function removeActiveClasses() {
        buttons.forEach(btn => btn.classList.remove('active'));
        dropdownLinks.forEach(lnk => lnk.classList.remove('active'));
    }

    // Add event listener for main navigation buttons
   

    // Add event listener for dropdown links
    dropdownLinks.forEach(link => {
        link.addEventListener('click', function() {
            removeActiveClasses();
            // Add active class to the parent button of the clicked dropdown link
            this.closest('.nav-item').querySelector('.x').classList.add('active');
            // Add active class to the clicked dropdown link
          //  this.classList.add('active');
        });
    })
    const currentURL = window.location.href;
    dropdownLinks.forEach(link => {
        if (currentURL.includes(link.getAttribute('href'))) {
            // Add active class to the parent button of the matching dropdown link
            link.closest('.nav-item').querySelector('.x').classList.add('active');
            // Add active class to the matching dropdown link
            link.classList.add('active');
        }
    });
})
