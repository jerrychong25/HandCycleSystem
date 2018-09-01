(function(){
    // Initialize Firebase
    var config = {
        apiKey: "AIzaSyDVEou1tV_u67pMv-UccginNq6MeveRClg",
        authDomain: "telemedicine-42de1.firebaseapp.com",
        databaseURL: "https://telemedicine-42de1.firebaseio.com",
        projectId: "telemedicine-42de1",
        storageBucket: "telemedicine-42de1.appspot.com",
        messagingSenderId: "120584880897"
    };
    firebase.initializeApp(config);

    const ButtonRegister = document.getElementById('ButtonRegister');

    ButtonRegister.addEventListener('click', handleSignUp, false);
}());

function handleSignUp(){
    // Get ParentName, ChildName, Email and Password
    var TextParentName = document.getElementById('TextParentName').value;
    var TextChildName = document.getElementById('TextChildName').value;
    var TextEmail = document.getElementById('TextEmail').value;
    var TextPassword = document.getElementById('TextPassword').value;
    var database = firebase.database();

    if (TextParentName.length < 4) {
        alert('Please enter parent name');
        return;
    }

    if (TextChildName.length < 4) {
        alert('Please enter child name');
        return;
    }

    if (TextEmail.length < 4) {
        alert('Please enter an email address');
        return;
    }

    if (TextPassword.length < 4) {
        alert('Please enter a password');
        return;
    }

    // Sign Up
    firebase.auth().createUserWithEmailAndPassword(TextEmail, TextPassword).catch(function(error) {
        // Handle Errors here.
        var errorCode = error.code;
        var errorMessage = error.message;
        // [START_EXCLUDE]
        if (errorCode == 'auth/weak-password') {
           alert('The password is too weak');
        } else {
           alert(errorMessage);
        }
        console.log(error);
        // [END_EXCLUDE]
    });

    // Redirect After Sign Up
    firebase.auth().onAuthStateChanged(function(user) {
        if(user) {
            // var ref = database.ref('UserDetails');
            // ref.on('value',writeUserData(TextParentName, TextChildName, TextEmail),errData);

            writeUserData(TextParentName, TextChildName, TextEmail);
            window.location = 'admin.html';
        }
    });
}

function writeUserData(parent_name, child_name, email) {

    // Get new user key (PushID).
    var user_key = firebase.database().ref('UserDetails/').push().key;

    var usersRef = firebase.database().ref('UserDetails/'+ user_key);
    usersRef.set({
        UserName: parent_name,
        UserChildName: child_name,
        UserEmail: email,
        RehabilitationDetails: "",
    });
}

function errData(err){
    console.log('Error!');
    console.log(err);
}