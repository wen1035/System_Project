#include <iostream>
#include <iomanip>
#include <fstream>
using namespace::std;

struct MemberRecord
{
    char email[40];
    char password[24];
    char IDNumber[12];
    char name[12];
    char phone[12];
};

struct Movie
{
    int movieCode;
    int prices[4]; // prices[0]:adult, prices[1]:concession, prices[2]:disability, prices[3]:elderly
    bool dates[9]; // dates[i] is true if and only if the movie is available on i-th date
    bool sessionTimes[17]; // sessionTimes[i] is true if and only if the movie is available on i-th session
    bool occupiedSeats[9][17][8][12]; // occupiedSeats[i][j] is the occupied Seats for all accounts
};                                           // at j-th session time on i-th date

struct BookingInfo
{
    char email[40];
    int movieCode;
    int dateCode;
    int sessionTimeCode;
    int numTickets[4]; // numTickets[0]: the number of adult tickets,
                         // numTickets[1]: the number of concession tickets,
                         // numTickets[2]: the number of disability tickets,
                         // numTickets[3]: the number of elderly tickets
    char seletedSeats[24][4]; // seleted seats for the user with the specified email
};

char hours[17][8] = { "09:00", "10:00", "11:00", "12:00", "13:00", "14:00", "15:00", "16:00", "17:00",
                          "18:00", "19:00", "20:00", "21:00", "22:00", "23:00", "00:00", "01:00" };

void loadMemberInfo(MemberRecord memberDetails[], int& numMembers);
void loadBookingHistories(BookingInfo bookingHistories[], int& numBookings);
void loadMovies(Movie movies[], int& numMovies);
void loadMovieNames(char movieNames[][60], int numMovies);
void loadAvailableDates(char availableDates[][12], int& numDates);

int inputAnInteger(int begin, int end);
void signIn(MemberRecord memberDetails[], int numMembers, Movie movies[], char movieNames[][60], int numMovies,
    BookingInfo bookingHistories[], int& numBookings, char availableDates[][12], int numDates);
bool illegal(char email[], char password[], MemberRecord memberDetails[], int numMembers, int& recordNumber);
void accountInfor(MemberRecord memberDetails[], int numMembers, int recordNumber);

void buyTickets(BookingInfo bookingHistories[], int& numBookings, Movie movies[], char movieNames[][60],
    int numMovies, char availableDates[][12], int numDates, char email[]);
void selectSeats(BookingInfo bookingHistories[], int numBookings, Movie movies[]);

void displaySessionTimes(Movie movies[], char movieNames[][60], int numMovies,
    char availableDates[][12], int numDates);
void display(Movie movies[], BookingInfo bookingHistory);
void displayBookingHistory(BookingInfo bookingHistories[], int numBookings, Movie movies[],
    char movieNames[][60], char availableDates[][12], char email[]);

void newMember(MemberRecord memberDetails[], int& numMembers);
bool existingID(char newIDNumber[], MemberRecord memberDetails[], int& numMembers);
bool existingEmail(char newEmail[], MemberRecord memberDetails[], int& numMembers);

void saveMemberInfo(MemberRecord memberDetails[], int numMembers);
void saveMovies(Movie movies[], int numMovies);
void saveBookingHistories(BookingInfo bookingHistories[], int numBookings);

int main()
{
    MemberRecord memberDetails[100] = {};
    int numMembers = 0;
    loadMemberInfo(memberDetails, numMembers);

    BookingInfo bookingHistories[1000] = {};
    int numBookings = 0;
    loadBookingHistories(bookingHistories, numBookings);

    Movie movies[30] = {};
    int numMovies = 0;
    loadMovies(movies, numMovies);

    char movieNames[30][60] = {};
    loadMovieNames(movieNames, numMovies);

    char availableDates[10][12];
    int numDates;
    loadAvailableDates(availableDates, numDates);

    cout << "Welcome to Vieshow Cinemas Taipei QSquare system\n";

    int choice;

    while (true)
    {
        cout << "\n1. Sign In\n";
        cout << "2. New Member\n";
        cout << "3. End\n";

        do cout << "\nEnter your choice (1~3): ";
        while ((choice = inputAnInteger(1, 3)) == -1);
        cout << endl;

        switch (choice)
        {
        case 1:
            signIn(memberDetails, numMembers, movies, movieNames, numMovies,
                bookingHistories, numBookings, availableDates, numDates);
            break;

        case 2:
            newMember(memberDetails, numMembers);
            break;

        case 3:
            saveMemberInfo(memberDetails, numMembers);
            saveMovies(movies, numMovies);
            saveBookingHistories(bookingHistories, numBookings);
            cout << "Thank you...\n\n";
            system("pause");
            return 0;

        default:
            cout << "Input Error!\n\n";
            break;
        }
    }

    system("pause");
}

//
void loadMemberInfo(MemberRecord memberDetails[], int& numMembers)
{
    ifstream inFile("Member Info.dat", ios::out | ios::binary);
    if (!inFile)
    {
        cerr << "File could not be opened" << endl;
        system("pause");
        exit(1);
    }//end if
    while (!inFile.eof())
    {
        inFile.read(reinterpret_cast<char*>(&memberDetails[numMembers]), sizeof(MemberRecord));//將字串放入到array中
        numMembers++;
    }
    inFile.close();
}


void loadBookingHistories(BookingInfo bookingHistories[], int& numBookings)
{
    ifstream inFile("Booking Histories.dat", ios::out | ios::binary);

    if (!inFile)
    {
        cerr << "File could not be opened" << endl;
        system("pause");
        exit(1);
    }//end if
    while (inFile.read(reinterpret_cast<char*>(&bookingHistories[numBookings]), sizeof(bookingHistories[numBookings])))
    {
        numBookings++;
    }

    inFile.close();
}


void loadMovies(Movie movies[], int& numMovies)
{
    ifstream inFile("Movies.dat", ios::out | ios::binary);

    if (!inFile)
    {
        cerr << "File could not be opened" << endl;
        system("pause");
        exit(1);
    }//end if
    while (inFile.read(reinterpret_cast<char*>(&movies[numMovies]), sizeof(movies[numMovies])))
    {
        numMovies++;
    }

    inFile.close();
}


void loadMovieNames(char movieNames[][60], int numMovies)
{
    ifstream inFile("Movie Names.txt");
    if (!inFile)
    {
        cout << "File could not be opened" << endl;
        system("pause");
        exit(1);
    }//end if

    for (int number = 0; number < numMovies; number++)
    {
        inFile.getline(movieNames[number], 60, '\n');
    }
    inFile.close();
}


void loadAvailableDates(char availableDates[][12], int& numDates)
{
    ifstream inFile("Available Dates.txt");
    if (!inFile)
    {
        cout << "File could not be opened" << endl;
        system("pause");
        exit(1);
    }//end if
    numDates = 0;
    while (inFile.getline(availableDates[numDates], 12, '\n'))
    {
        numDates++;
    }
    inFile.close();
}


//從鍵盤輸入一個整數，然後
//如果它屬於[begin，end]，則返回整數，否則返回-1。
int inputAnInteger(int begin, int end)
{
    int a;
    cin >> a;
    if (a< begin || a>end)
    {
        return -1;
    }
    return a;
}


void signIn(MemberRecord memberDetails[], int numMembers, Movie movies[], char movieNames[][60], int numMovies,
    BookingInfo bookingHistories[], int& numBookings, char availableDates[][12], int numDates)
{
    MemberRecord abc;
    int choice = 0;
    int recordNumber = 1;//只是亂抓值
    while (true)
    {
        cout << "Enter email address :";
        cin >> abc.email;
        cout << "Enter password : ";
        cin >> abc.password;
        if (illegal(abc.email, abc.password, memberDetails, numMembers, recordNumber))
        {

            break;
        }
        cout << "Sorry, unrecognized email or password." << endl;
    }
    while (true)//如果帳密相符就跑出第二個表單
    {
        cout << endl << "Enter your choice (1~4): " << endl;
        cout << "1. Account Information" << endl;
        cout << "2. Buy Tickets" << endl;
        cout << "3. My Bookings" << endl;
        cout << "4. Sign Out" << endl;

        choice = inputAnInteger(1, 4);

        switch (choice)
        {
        case 1:
            cout << endl;
            accountInfor(memberDetails, numMembers, recordNumber);
            break;

        case 2:
            cout << endl;
            buyTickets(bookingHistories, numBookings, movies, movieNames, numMovies, availableDates, numDates, abc.email);
            break;

        case 3:
            cout << endl;
            displayBookingHistory(bookingHistories, numBookings, movies, movieNames, availableDates, abc.email);
            break;

        case 4:
            return;
        }
    }
}

//如果有成員，則返回true
//其電子郵件和密碼分別等於指定的電子郵件和密碼
bool illegal(char email[], char password[], MemberRecord memberDetails[], int numMembers, int& recordNumber)
{
    int z;
    for (z = 0; z <= numMembers - 1; z++)
    {
        if ((strcmp(memberDetails[z].email, email) == 0) && (strcmp(memberDetails[z].password, password) == 0))
        {
            recordNumber = z;
            return true;
        }

    }
    return false;
}

//辦新帳號
void accountInfor(MemberRecord memberDetails[], int numMembers, int recordNumber)
{
    int a;
    cout << "\n1.Name:" << memberDetails[recordNumber].email << endl;
    cout << "2.Email Address:" << memberDetails[recordNumber].IDNumber << endl;
    cout << "3.Phone Number:" << memberDetails[recordNumber].name << endl;
    cout << "4.ID Number:" << memberDetails[recordNumber].password << endl;
    cout << "5.Password:" << memberDetails[recordNumber].phone << endl;
    cout << "Which one do you want to modify (0 – not modify)? " << endl;
    while (1)
    {
        cin >> a;
        switch (a)
        {
        case 0:
            return;
        case 1:
            cout << "Enter correct data :";
            cin >> memberDetails[recordNumber].email;
            cout << "\nSuccessful!\n";
            return;

        case 2:
            cout << "Enter correct data :";
            cin >> memberDetails[recordNumber].IDNumber;
            cout << "\nSuccessful!\n";
            return;

        case 3:
            cout << "Enter correct data :";
            cin >> memberDetails[recordNumber].name;
            cout << "\nSuccessful!\n";
            return;

        case 4:
            cout << "Enter correct data :";
            cin >> memberDetails[recordNumber].password;
            cout << "\nSuccessful!\n";
            return;
        case 5:
            cout << "Enter correct data :";
            cin >> memberDetails[recordNumber].phone;
            cout << "\nSuccessful!\n";
            return;
        default:
            cout << "\nInput Error! Please try again:";
            break;
        }
    }


}

void buyTickets(BookingInfo bookingHistories[], int& numBookings, Movie movies[], char movieNames[][60],
    int numMovies, char availableDates[][12], int numDates, char email[])
{
    int movie_ch;
    int date_ch;
    int time_ch;

    //輸出所有電影的資訊
    displaySessionTimes(movies, movieNames, numMovies, availableDates, numDates);

    //選電影編號
    do
    {
        cout << "Enter movie code (0 - 11): ";
    } while ((movie_ch = inputAnInteger(0, 11)) == -1);
    bookingHistories[numBookings].movieCode = movie_ch;
    cout << endl;

    //選電影日期
    do
    {
        cout << "Enter date code (0 - 8): ";
    } while ((date_ch = inputAnInteger(0, 8)) == -1 || movies[movie_ch].dates[date_ch] == false);//不是上面有的日期
    bookingHistories[numBookings].dateCode = date_ch;
    cout << endl;

    //選電影時間
    do
    {
        cout << "Enter session time code (0 - 16): ";
    } while ((time_ch = inputAnInteger(0, 16)) == -1 || movies[movie_ch].sessionTimes[time_ch] == false);
    bookingHistories[numBookings].sessionTimeCode = time_ch;
    cout << endl;

    //輸出選好的電影資訊和金額的介紹
    cout << "Movie: " << movieNames[movie_ch] << endl;
    cout << "Date: " << availableDates[date_ch] << endl;
    cout << "Show Time: " << hours[time_ch] << endl;
    cout << "Price: Adult-" << movies[movie_ch].prices[0] << ", Concession-" << movies[movie_ch].prices[1]
        << ", Disability-" << movies[movie_ch].prices[2] << ", Elderly-" << movies[movie_ch].prices[3] << endl << endl;

    //選多少票
    int tickets = 0;
    do
    {
        for (int i = 0; i < 4; i++)
        {
            do
            {
                if (i == 0)
                {
                    cout << "Enter the number of adult tickets (0 - 6): ";
                }
                if (i == 1)
                {
                    cout << "Enter the number of concession tickets (0 - 6): ";
                }
                if (i == 2)
                {
                    cout << "Enter the number of disability tickets (0 - 6): ";
                }
                if (i == 3)
                {
                    cout << "Enter the number of elderly tickets (0 - 6): ";
                }
            } while ((bookingHistories[numBookings].numTickets[i] = inputAnInteger(0, 6)) == -1);

            tickets += bookingHistories[numBookings].numTickets[i];
        }
        cout << endl;
    } while (tickets == 0);

    //輸出總共買的票
    display(movies, bookingHistories[numBookings]);
    //輸出位子
    selectSeats(bookingHistories, numBookings, movies);
    //用於歷史紀錄
    for (int i = 0; i <= strlen(email); i++)
    {
        bookingHistories[numBookings].email[i] = email[i];
    }
    numBookings++;
}

//輸出位子
void selectSeats(BookingInfo bookingHistories[], int numBookings, Movie movies[])
{
    int tickets = 0;
    char left[8]{ '0','1','2','3','4','5','6','7' };
    char line[12]{ 'A','B','C' ,'D' ,'E' ,'F' ,'G' ,'H' ,'I' ,'J' ,'K' ,'L' };

    for (int a = 0; a < 4; a++)
    {
        tickets += bookingHistories[numBookings].numTickets[a];
    }
    cout << " ";

    //輸出上方條
    for (int i = 0; i < 12; i++)
    {
        cout << " " << line[i];
    }
    cout << endl;

    //輸出左邊條
    for (int j = 0; j < 8; j++)
    {
        cout << left[j];
        for (int a = 0; a < 12; a++)
        {
            cout << " " << movies[bookingHistories[numBookings].movieCode].occupiedSeats
                [bookingHistories[numBookings].dateCode][bookingHistories[numBookings].sessionTimeCode][j][a];
        }
        cout << endl;
    }


    cout << endl << "Select " << tickets << " seats(e.g. 0A) :" << endl;

    for (int s = 0; s < tickets; s++)
    {
        cout << "? ";

        while (true)
        {
            cin.getline(bookingHistories[numBookings].seletedSeats[s], 10, '\n');

            if (strlen(bookingHistories[numBookings].seletedSeats[s]) == 2
                && ('0' <= bookingHistories[numBookings].seletedSeats[s][0] && bookingHistories[numBookings].seletedSeats[s][0] <= '7'
                    && 'A' <= bookingHistories[numBookings].seletedSeats[s][1] && bookingHistories[numBookings].seletedSeats[s][1] <= 'L'))
            {

                if (movies[bookingHistories[numBookings].movieCode].occupiedSeats
                    [bookingHistories[numBookings].dateCode][bookingHistories[numBookings].sessionTimeCode]
                    [bookingHistories[numBookings].seletedSeats[s][0] - '0'][bookingHistories[numBookings].seletedSeats[s][1] - 'A'] == 0)
                {

                    movies[bookingHistories[numBookings].movieCode].occupiedSeats
                        [bookingHistories[numBookings].dateCode][bookingHistories[numBookings].sessionTimeCode]
                        [bookingHistories[numBookings].seletedSeats[s][0] - '0'][bookingHistories[numBookings].seletedSeats[s][1] - 'A'] = 1;
                    break;
                }
                else
                {
                    cout << endl << "This seat has been occupied. Please select another seat." << endl << "? ";
                }
            }

        }
    }
    cout << endl << "Successful!" << endl << endl;
}

//輸出所有電影的資訊
void displaySessionTimes(Movie movies[], char movieNames[][60], int numMovies,
    char availableDates[][12], int numDates)
{
    for (int movie = 0; movie < numMovies; movie++)
    {
        if (movie < 10)//排版而已
        {
            cout << " " << movie << ". Movie: " << movieNames[movie] << endl;
        }
        else
        {
            cout << movie << ". Movie: " << movieNames[movie] << endl;
        }
        //輸出日期
        cout << "    Date:";
        for (int date = 0; date < numDates; date++)
        {
            if (movies[movie].dates[date] == true)
            {
                cout << "  " << date << ". " << availableDates[date] << ", ";
            }
        }
        //輸出時間
        cout << endl << "    Session Time:";
        for (int time = 0; time < 17; time++)
        {
            if (movies[movie].sessionTimes[time] == true)
            {
                cout << "  " << time << ". " << hours[time] << ",";
            }
        }
        cout << endl << endl;
    }
}

////輸出總共買的票
void display(Movie movies[], BookingInfo bookingHistory)
{
    int total = 0;
    cout << "             No. of Tickets  Price  Subtotal" << endl;
    for (int i = 0; i < 4; i++)
    {
        if (bookingHistory.numTickets[i] != 0)
        {
            if (i == 0)
            {
                cout << "Adult ticket              " << bookingHistory.numTickets[i] << "    ";
            }
            if (i == 1)
            {
                cout << "Concession ticket         " << bookingHistory.numTickets[i] << "    ";
            }
            if (i == 2)
            {
                cout << "Disability ticket         " << bookingHistory.numTickets[i] << "    ";
            }
            if (i == 3)
            {
                cout << "Elderly ticket            " << bookingHistory.numTickets[i] << "    ";
            }
            cout << movies[bookingHistory.movieCode].prices[i] << "       ";
            cout << bookingHistory.numTickets[i] * movies[bookingHistory.movieCode].prices[i] << endl;
            total += bookingHistory.numTickets[i] * movies[bookingHistory.movieCode].prices[i];
        }
    }
    cout << endl << "Total Amount For Tickets: " << total << endl << endl;
}

//歷史紀錄
void displayBookingHistory(BookingInfo bookingHistories[], int numBookings, Movie movies[],
    char movieNames[][60], char availableDates[][12], char email[])
{
    int abc = 0;

    for (int j = 0; j < numBookings; j++)
    {
        if (strcmp(bookingHistories[j].email, email) == 0)
        {

            cout << "Booking History:" << endl << endl;
            cout << "Movie: " << movieNames[bookingHistories[j].movieCode] << endl;
            cout << "Date: " << availableDates[bookingHistories[j].dateCode] << endl;
            cout << "Show Time: " << hours[bookingHistories[j].sessionTimeCode] << endl;
            cout << "Seats: ";
            //輸出之前選的位子 
            for (int s = 0; s < 24; s++)
            {
                cout << bookingHistories[j].seletedSeats[s] << "  ";
            }
            cout << endl << endl;
            display(movies, bookingHistories[j]);
            cout << "----------------------------------------------" << endl << endl;
            abc++;
        }
    }

    if (abc == 0)
    {
        cout << "No bookings!" << endl << endl;
    }
}


void newMember(MemberRecord memberDetails[], int& numMembers)
{
    MemberRecord abc;
    cout << "Enter your ID number:";
    cin >> abc.IDNumber;
    if (existingID(abc.IDNumber, memberDetails, numMembers))//IDnumber存在
    {
        cout << "An account already exists with the ID number!" << endl;
        return;
    }

    cout << "Enter your name:";
    cin >> abc.name;

    cout << "Enter an email address:";
    cin >> abc.email;
    if (existingEmail(abc.email, memberDetails, numMembers))//email存在
    {
        cout << "An account already exists with the email address!" << endl;
        return;
    }

    cout << "Enter a password:";
    cin >> abc.password;

    cout << "Enter your phone number:";
    cin >> abc.phone;

    memberDetails[numMembers] = abc;//把資料放進memberDetails[]
    numMembers++;//位子

    cout << "Successful!" << endl;
    return;
}

//如果有一個IDNumber等於newIDNumber的成員，則返回true
bool existingID(char newIDNumber[], MemberRecord memberDetails[], int& numMembers)
{
    for (int j = 0; j < numMembers; j++)
    {
        if (strcmp(newIDNumber, memberDetails[j].IDNumber) == 0)
        {
            return true;
        }

    }
    return false;
}

bool existingEmail(char newEmail[], MemberRecord memberDetails[], int& numMembers)
{
    for (int i = 0; i < numMembers; i++)
    {
        if (strcmp(newEmail, memberDetails[i].email) == 0)
        {
            return true;
        }

    }
    return false;
}

void saveMemberInfo(MemberRecord memberDetails[], int numMembers)
{
    ofstream outFile("Member Info.dat", ios::out | ios::binary);
    if (!outFile)
    {
        cout << "File could not be opened" << endl;
        system("pause");
        exit(1);
    }
    for (int a = 0; a < numMembers; a++)
    {
        outFile.write(reinterpret_cast<const char*>(&memberDetails[a]), sizeof(memberDetails[a]));
    }

    outFile.close();
}

void saveMovies(Movie movies[], int numMovies)
{
    ofstream outFile("Movies.dat", ios::out | ios::binary);
    if (!outFile)
    {
        cout << "File could not be opened" << endl;
        system("pause");
        exit(1);
    }
    for (int k = 0; k < numMovies; k++)
    {
        outFile.write(reinterpret_cast<const char*>(&movies[k]), sizeof(movies[k]));
    }

    outFile.close();
}

void saveBookingHistories(BookingInfo bookingHistories[], int numBookings)
{
    ofstream outFile("Booking Histories.dat", ios::out | ios::binary);
    if (!outFile)
    {
        cout << "File could not be opened" << endl;
        system("pause");
        exit(1);
    }
    for (int i = 0; i < numBookings; i++)
    {
        outFile.write(reinterpret_cast<const char*>(&bookingHistories[i]), sizeof(bookingHistories[i]));
    }
    outFile.close();
}


