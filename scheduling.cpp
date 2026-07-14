#include <iostream>;
#include <String>;
# include <vector>;
# include <ctime>;
# include<regex>;

using namespace std;
//dd

// juz for scheduling module
// so other fun no related to scheduling module, i wont code so detail


struct bookingRoom {
	string bookingDate; //later convert to time_t data type
	string bookingTime; //later convert to time_t data type
	string name; // who booked the room
	bool status;

};

struct Room {
	string roomName;
	string building;
	string floor;
	string detail; // describe the facilities of the room
	int capacity; 
	double cost;
	bookingRoom booking; // booking details
	string type; // middle, big, small, etc 
};


//check repetation 
bool isRepeatedRoomDetail(vector <Room>& roomList, const string& roomDetail, string Room::* field, string msg) {
	string lowerRoom1 = roomDetail;
	transform(lowerRoom1.begin(), lowerRoom1.end(), lowerRoom1.begin(), ::tolower);
	string lowerRoom2;

	for (Room room : roomList) {

		lowerRoom2 = room.*field;

		transform(lowerRoom2.begin(), lowerRoom2.end(), lowerRoom2.begin(), ::tolower);

		if (lowerRoom2 == lowerRoom1) {
			cout << msg;
			return false;
		}
	}

	return true;
}

// validation 
bool isValidRoomName(vector <Room> &roomList,const string& roomName) {
	// Define a regex pattern for valid room names 
	string lowerRoom;
	regex pattern("^[a-zA-Z0-9]{3,}");
	if (!regex_match(roomName, pattern)) {
		cout << "Invalid Room Name!Room Name must be at least 3 characters long and contain only letters and numbers.\n";
		return false;
	}
	return isRepeatedRoomDetail(roomList, roomName, &Room::roomName, "Room Name already exists! Please enter a different Room Name.\n");
}

bool isValidRoomBuilding(vector <Room> &roomList,const string& roomBuilding) {
	// Define a regex pattern for valid room buildings 
	regex pattern("^[a-zA-Z0-9]{3,}");
	if (!regex_match(roomBuilding, pattern)) {
		cout << "Invalid Room Building! Room Building must be at least 3 characters long and contain only letters and numbers.\n";
		return false;
	}
	return isRepeatedRoomDetail(roomList, roomBuilding, &Room::building, "Room Building already exists! Please enter a different Room Building.\n");
}

bool isValidRoomFloor(vector <Room> &roomList,const string& roomFloor) {
	// Define a regex pattern for valid room floors 
	regex pattern("^[a-zA-Z0-9]{1,}");
	if (!regex_match(roomFloor, pattern)) {
		cout << "Invalid Room Floor! Room Floor must be at least 1 character long and contain only letters and numbers.\n";
		return false;
	}
	return isRepeatedRoomDetail(roomList, roomFloor, &Room::floor, "Room Floor already exists! Please enter a different Room Floor.\n");
}

bool isValidRoomDetail(vector <Room> &roomList,const string& roomDetail) {
	// Define a regex pattern for valid room details 
	regex pattern("^[a-zA-Z0-9]{3,}");
	if (!regex_match(roomDetail, pattern)) {
		cout << "Invalid Room Detail! Room Detail must be at least 3 characters long and contain only letters and numbers.\n";
		return false;
	}
	return true;
}

bool isValidRoomCapacity(vector <Room> &roomList,const string& roomCapacity) {
	// Define a regex pattern for valid room capacity 
	regex pattern("^[0-9]{1,}");
	if (!regex_match(roomCapacity, pattern)) {
		cout << "Invalid Room Capacity! Room Capacity must be a positive integer.\n";
		return false;
	}
	return true;
}

bool isValidRoomCost(vector <Room> &roomList,const string& roomCost) {
	// Define a regex pattern for valid room cost 
	regex pattern("^[0-9]+(\\.[0-9]{1,2})?$");
	if (!regex_match(roomCost, pattern)) {
		cout << "Invalid Room Cost! Room Cost must be a positive number with up to 2 decimal places.\n";
		return false;
	}
	return true;
}

bool isValidRoomType(vector <Room> &roomList,const string& roomType) {
	// Define a regex pattern for valid room types 
	regex pattern("^[a-zA-Z]{3,}");
	if (!regex_match(roomType, pattern)) {
		cout << "Invalid Room Type! Room Type must be at least 3 characters long and contain only letters.\n";
		return false;
	}
	return true;
}

bool isValidBookingDate(vector <Room> &roomList,const string& bookingDate) {
	// Define a regex pattern for valid booking dates 
	regex pattern("^\\d{4}-\\d{2}-\\d{2}$");
	if (!regex_match(bookingDate, pattern)) {
		cout << "Invalid Booking Date! Booking Date must be in the format YYYY-MM-DD.\n";
		return false;
	}
	return true;
}

bool isValidBookingTime(vector <Room> &roomList,const string& bookingTime) {
	// Define a regex pattern for valid booking times 
	regex pattern("^\\d{2}:\\d{2}$");
	if (!regex_match(bookingTime, pattern)) {
		cout << "Invalid Booking Time! Booking Time must be in the format HH:MM.\n";
		return false;
	}
	return true;
}

bool isValidBookingName(vector <Room> &roomList,const string& bookingName) {
	// Define a regex pattern for valid booking names 
	regex pattern("^[a-zA-Z ]{3,}$");
	if (!regex_match(bookingName, pattern)) {
		cout << "Invalid Booking Name! Booking Name must be at least 3 characters long and contain only letters and spaces.\n";
		return false;
	}
	return true;
}


// reusable validation
bool validation(string &newData, vector <Room>& roomList, bool (*operation)(vector<Room>&,const string&)) {
	if (operation(roomList,newData)) {
		return true;
	}
	else {
		return false;
	}
}

void addRoom(vector <Room> &roomList) {
	Room newRoom; // create a new room object
	bookingRoom newBooking; // create a new booking object
	bool success = false;
	while (!success)
	{
		cout << "Enter Room Name: ";
		cin >> newRoom.roomName;
		success = validation( newRoom.roomName,  roomList, isValidRoomName);
		
		if (!success) {
			addRoom(roomList); // recursively call addRoom to re-enter the room details
			break;
		}
		
		cout << "Enter Room building: ";
		cin >> newRoom.building;

		if (!success) {
			addRoom(roomList);
			break;
		}
		cout << "Enter Room Floor: ";
		cin >> newRoom.floor;

		if (!success) {
			addRoom(roomList); 
			break;
		}
		cout << "Enter Room Detail: ";
		cin >> newRoom.detail;

		if (!success) {
			addRoom(roomList); 
			break;
		}
		cout << "Enter Room Capacity: ";
		cin >> newRoom.capacity;

		if (!success) {
			addRoom(roomList);
			break;
		}
		cout << "Enter Room Cost: ";
		cin >> newRoom.cost;

		if (!success) {
			addRoom(roomList); 
			break;
		}
		cout << "Enter Room Type: ";
		cin >> newRoom.type;

		if (!success) {
			addRoom(roomList); 
			break;
		}
	}
	roomList.push_back(newRoom);
	cout << "Room Added Successfully!" << endl;
	return;

}

void roomManagement(vector <Room>& roomList) {
	int option;
	cout << "Welcome to Room Management \n";
	cout << "1. Add Room \n";
	cout << "2. Remove Room \n";
	cout << "3. View Rooms \n";
	cout << "4. Back to Admin Home Page \n";
	cout << "Enter Your Option"<<endl;
	cin >> option;
	switch (option)
	{
	case 1:
		addRoom(roomList);
		break;
	case 2:
		cout << "You are in Remove Room \n";
		break;
	case 3:
		cout << "You are in View Rooms \n";
		break;
	default:
		break;
	}
}

void adminHomePage(vector <Room>& roomList) {
	int option;
	bool continueLoop = true;
	do {
		cout << "Welcome Admin \n";
		cout << "1. Room Management";
		cout << "0. Exit";
		cout << "Enter Your Option" << endl;

		cin >> option;

		switch (option)
		{
		case 1:
			roomManagement(roomList);
			break;
		case 0:
			continueLoop = false;
			break;
		default:
			break;
		}

	} while (!continueLoop);

}


int main() {

	//retrieve data


	vector <Room> roomList;

	roomList.push_back({ "Room1", "Building1", "Floor1", "Detail1", 10, 100.0, {"2023-06-01", "10:00", "John Doe", true}, "Small" });

	cout << "Select Your Identity \n";
	cout << "1. Student \n";
	cout << "2. Teacher \n";
	cout << "3. Admin \n";
	int identity;
	cin >> identity;

	switch (identity)
	{
	case 1:
		cout << "You are a Student \n";
		break;
	case 2:
		cout << "You are a Teacher \n";
		break;

	case 3:
		adminHomePage(roomList);
		break;
	default:
		break;
	}

	return 0;
}
