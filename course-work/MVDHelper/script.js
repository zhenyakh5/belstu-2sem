'use strict'
document.addEventListener("DOMContentLoaded", function () {

    // Плавное прокручивание
    document.getElementById('priceLink').addEventListener('click', function() {
        document.getElementById('subscriptions').scrollIntoView({ behavior: 'smooth' });
    });
    document.getElementById('priceLink2').addEventListener('click', function() {
        document.getElementById('subscriptions').scrollIntoView({ behavior: 'smooth' });
    });

    // Открытие модального окна
    let subscriptionButtons = document.querySelectorAll('.subscriptionButton');
    subscriptionButtons.forEach((function (button) {
        button.addEventListener('click', function () {
            let modal = document.getElementById("modal");

            modal.style.display = "block";
            modal.classList.add("fade-in");
        })
    }))

    // Письмо "было" отправлено
    document.getElementById('sendEmail').addEventListener('click', function () {
        let emailInput = document.getElementById("emailInput");
        let emailInputValue = emailInput.value.trim();

        if (emailInputValue.includes('@')) {
            let modalInput = document.getElementById("modalInput");
            modalInput.style.display = "none";

            let modalTitle = document.getElementById('modalTitle');
            modalTitle.innerText = "Письмо с инструкциями было отправлено.";
        } else {
            alert("Пожалуйста, введите корректный адрес электронной почты.");
        }
    });

    // Закрытие модального окна
    document.getElementById('closeModal').addEventListener('click', function () {
        let modal = document.getElementById("modal");
        modal.classList.remove("fade-in");
        modal.classList.add("fade-out");

        setTimeout(function() {
            modal.style.display = "none";
            modal.classList.remove("fade-out");
        }, 500);
    })
})