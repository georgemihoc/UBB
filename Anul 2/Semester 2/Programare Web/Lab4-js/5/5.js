var index = 1;
var timer = 0;

showSlides(index);

function changeSlide(n) {
    clearTimeout(timer);
    showSlides(index += n);
}

function showSlides(n) {
    var i;
    var slides = document.getElementsByClassName("slides");
    if (n===undefined)
    {
        index += 1;
        n = index;
    }
    if (n > slides.length) {
        index = 1
    }
    if (n < 1) {
        index = slides.length
    }
    for (i = 0; i < slides.length; i++) {
        slides[i].style.display = "none";
    }
    slides[index-1].style.display = "block";
    timer = setTimeout(showSlides, 2000);
}