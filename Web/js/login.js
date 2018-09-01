(function(){
    // Initialize Firebase
    const config = {
        apiKey: "AIzaSyDVEou1tV_u67pMv-UccginNq6MeveRClg",
        authDomain: "telemedicine-42de1.firebaseapp.com",
        databaseURL: "https://telemedicine-42de1.firebaseio.com",
        projectId: "telemedicine-42de1",
        storageBucket: "telemedicine-42de1.appspot.com",
        messagingSenderId: "120584880897"
    };
    firebase.initializeApp(config);

    const ButtonLogin = document.getElementById('ButtonLogin');

    ButtonLogin.addEventListener('click', handleLogin, false);
}());

function handleLogin() {
    if (firebase.auth().currentUser) {
        // [START signout]
        firebase.auth().signOut();
        // [END signout]
    } else {
        var TextEmail = document.getElementById('TextEmail').value;
        var TextPassword = document.getElementById('TextPassword').value;
        if (TextEmail.length < 4) {
            alert('Please enter an email address');
            return;
        }
        if (TextPassword.length < 4) {
            alert('Please enter a password');
            return;
        }
        // Sign in with email and pass.
        // [START authwithemail]
        firebase.auth().signInWithEmailAndPassword(TextEmail, TextPassword).catch(function(error) {
            // Handle Errors here.
            var errorCode = error.code;
            var errorMessage = error.message;
            // [START_EXCLUDE]
            if (errorCode === 'auth/wrong-password') {
                alert('Wrong password.');
            } else {
                alert(errorMessage);
            }
            console.log(error);
            document.getElementById('quickstart-sign-in').disabled = false;
            // [END_EXCLUDE]
        });
        // [END authwithemail]

        // Redirect Login
        firebase.auth().onAuthStateChanged(function(user) {
            if(user) {
                window.location = 'admin.html';
            }
        });
    }
    document.getElementById('quickstart-sign-in').disabled = true;
}