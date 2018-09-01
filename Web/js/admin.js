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
    var database = firebase.database();

    firebase.auth().onAuthStateChanged(function(user) {
        if(user) {
            var ref = database.ref('UserDetails');
            ref.on('value',gotData,errData);
        }
    });

    ButtonLogout.addEventListener('click', e => {
        firebase.auth().signOut();
        window.location = 'login.html';
    });
}());

function gotData(data) {
    // console.log(data.val());

    var user_key;
    var data_key = [];
    var parent_name;
    var child_name;
    var email;
    var child_date = [];
    var child_duration = [];
    var child_motor_speed = [];
    var child_orientation = [];
    var child_time_start = [];
    var child_time_stop = [];
    var data_length =  0;

    var ref_master = firebase.database().ref('UserDetails');
    var user = firebase.auth().currentUser;
    ref_master.orderByChild('UserEmail').equalTo(user.email).once('value', function (snapshot) {
        snapshot.forEach(function(child) {
            console.log("User Key: " + child.key);
            user_key = child.key;
        });
    });

    var ref_user= firebase.database().ref('UserDetails/');

    ref_user.orderByChild(user_key).on("child_added", function(data) {
        // console.log("Parent Name: " + data.val().UserName + " Child Name: " + data.val().UserChildName);
        parent_name = data.val().UserName;
        child_name = data.val().UserChildName;
        email = data.val().UserEmail;
    });

    console.log("Parent Name: " + parent_name);
    console.log("Child Name: " + child_name);
    console.log("Email: " + email);

    var user_content = '';
    user_content += '<tr>';
    user_content += '<td>' + parent_name + '</td>';
    user_content += '<td>' + child_name + '</td>';
    user_content += '<td>' + email + '</td>';
    user_content += '</tr>';

    $('#user_details_table').append(user_content);

    var ref_child = firebase.database().ref('UserDetails/'+ user_key + '/RehabilitationDetails');

    ref_child.orderByKey().on('child_added', function(data) {
        // console.log("Data Key: " + data.key);
        data_key.push(data.key);
        data_length++;
    });

    console.log("Data Key: " + data_key);

    // console.log("Data Key 1: " + data_key[0]);
    // console.log("Data Key 2: " + data_key[1]);
    // console.log("Data Key 3: " + data_key[2]);
    // console.log("Data Key 4: " + data_key[3]);

    ref_child.orderByChild(data_key[0]).on("child_added", function(data) {
        // console.log("Child Date: " + data.val().childDate + " Child Duration: " + data.val().childDuration + " Child Motor Speed: " + data.val().childMotorSpeed + " Child Orientation: " + data.val().childOrientation + " Child Time Start: " + data.val().childTimeStart + " Child Time Stop: " + data.val().childTimeStop);
        child_date.push(data.val().childDate);
        child_duration.push(data.val().childDuration);
        child_motor_speed.push(data.val().childMotorSpeed);
        child_orientation.push(data.val().childOrientation);
        child_time_start.push(data.val().childTimeStart);
        child_time_stop.push(data.val().childTimeStop);
    });

    console.log("Child Date: " + child_date);
    console.log("Child Duration: " + child_duration);
    console.log("Child Motor Speed: " + child_motor_speed);
    console.log("Child Orientation: " + child_orientation);
    console.log("Child Time: " + child_time_start);
    // console.log("Child Time Stop: " + child_time_stop);

    // console.log("Child Date 1: " + child_date[0]);
    // console.log("Child Date 2: " + child_date[1]);
    // console.log("Child Date 3: " + child_date[2]);
    // console.log("Child Date 4: " + child_date[3]);
    //
    // console.log("Child Duration 1: " + child_duration[0]);
    // console.log("Child Duration 2: " + child_duration[1]);
    // console.log("Child Duration 3: " + child_duration[2]);
    // console.log("Child Duration 4: " + child_duration[3]);
    //
    // console.log("Child Motor Speed 1: " + child_motor_speed[0]);
    // console.log("Child Motor Speed 2: " + child_motor_speed[1]);
    // console.log("Child Motor Speed 3: " + child_motor_speed[2]);
    // console.log("Child Motor Speed 4: " + child_motor_speed[3]);
    //
    // console.log("Child Orientation 1: " + child_orientation[0]);
    // console.log("Child Orientation 2: " + child_orientation[1]);
    // console.log("Child Orientation 3: " + child_orientation[2]);
    // console.log("Child Orientation 4: " + child_orientation[3]);
    //
    // console.log("Child Time Start 1: " + child_time_start[0]);
    // console.log("Child Time Start 2: " + child_time_start[1]);
    // console.log("Child Time Start 3: " + child_time_start[2]);
    // console.log("Child Time Start 4: " + child_time_start[3]);
    //
    // console.log("Child Time Stop 1: " + child_time_stop[0]);
    // console.log("Child Time Stop 2: " + child_time_stop[1]);
    // console.log("Child Time Stop 3: " + child_time_stop[2]);
    // console.log("Child Time Stop 4: " + child_time_stop[3]);

    for (var i = 0; i < data_length; i++) {
        var rehabilitation_content = '';
        rehabilitation_content += '<tr>';
        rehabilitation_content += '<td>' + child_date[i] + '</td>';
        rehabilitation_content += '<td>' + child_duration[i] + '</td>';
        rehabilitation_content += '<td>' + child_motor_speed[i] + '</td>';
        rehabilitation_content += '<td>' + child_orientation[i] + '</td>';
        rehabilitation_content += '<td>' + child_time_start[i] + '</td>';
        // rehabilitation_content += '<td>' + child_time_stop[i] + '</td>';
        rehabilitation_content += '</tr>';

        $('#rehabilitation_details_table').append(rehabilitation_content);
    }
}

function errData(err){
    console.log('Error!');
    console.log(err);
}