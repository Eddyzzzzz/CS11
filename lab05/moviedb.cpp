/*
 * CS 11: Lab 05
 * moviedb.cpp
 *
 * Purpose: Interact with arrays of structs by manipulating
 *          and searching a movie database
 *
 * Written by: Keisha Mukasa, Spring 2021
 * With updates by: Sam Berman (sberma04) and 
 *                  Jackson Parsells (jparse01), Fall 2021
 *
 * Modified by: Eddy Zhang, Spring 2022
 *
 */

#include <iostream>
#include <fstream>

using namespace std;

const int NUM_MOVIES = 450;
const int NUM_ACTORS = 5;

struct Movie
{
    string title;
    int    year;
    double gross;
    string director;
    string actors[NUM_ACTORS];
};

void read_movie_data(Movie movies[NUM_MOVIES]);
void find_movie(Movie movie_list[]);
void movie_in_year(Movie movie_list[]);
void three_information(Movie movie_list[]);
void highest_year(Movie movie_list[]);
void movie_with_actor(Movie movie_list[]);

int main()
{
    // This line of code declares a list of 450 movies obje
    Movie movie_list[NUM_MOVIES];

    // This function call is populating the movie list with all
    // the movies in the file. Do not worry about its implementation.
    read_movie_data(movie_list);

    /* TODO: Your lab code goes here */
    /*find_movie(movie_list);
    cout << endl;
    
    movie_in_year(movie_list);
    cout << endl;
    
    three_information(movie_list);
    cout << endl;
    
    highest_year(movie_list);
    cout << endl;
    
    movie_with_actor(movie_list);*/
    
    return 0;
}

/* 
 * TODO: YOUR FUNCTIONS GO HERE 
 */
 
 //Function for problem 1: find movie
 void find_movie(Movie movie_list[])
 {
    string name;
    cout << "Hi, please enter the name of the movie: ";
    getline(cin, name);
     
    for (int i = 0; i < NUM_MOVIES; ++i)
    {
        if (movie_list[i].title == name)
        {
            cout << movie_list[i].title << endl;
            cout << movie_list[i].year << endl;
            cout << movie_list[i].gross << endl;
            cout << movie_list[i].director << endl;
            for (int j = 0; j < NUM_ACTORS - 1; ++j)
            cout << movie_list[i].actors[j] << ", ";
            cout << movie_list[i].actors[NUM_ACTORS - 1] << endl;
            return;
        }
    }
    
    cout << name << " was not found in the movie database" << endl;
    
    return;
 }
    
//Function for problem 2: movie in given year
void movie_in_year(Movie movie_list[])
{
    int year;
    cout << "Hi, please enter the year you want to check: ";
    cin  >> year;
    int count = 0;
    
    for (int i = 0; i < NUM_MOVIES; ++i)
    {
        if (movie_list[i].year == year)
        {
            cout << movie_list[i].title << endl;
        }
        else
        ++count;
    }
    
    if (count == NUM_MOVIES)
    cout << "There is no movie found in " << year << endl;
    
    return;
}

//Function for problem 3: three information
void three_information(Movie movie_list[])
{
    double total = 0;
    double highest[2] = {0, movie_list[0].gross};
    double lowest[2]  = {0, movie_list[0].gross};
    
    for (int i = 0; i < NUM_MOVIES; ++i)
    {
        total += movie_list[i].gross;
        
        if (movie_list[i].gross >= highest[1])
        {
            highest[0] = i;
            highest[1] = movie_list[i].gross;
        }    
        
        if (movie_list[i].gross <= highest[1])
        {
            lowest[0] = i;
            lowest[1] = movie_list[i].gross;
        }            
    }
    
    double mean = total / NUM_MOVIES;
    
    cout << "The highest grossing movie is "; 
    cout << movie_list[(int)highest[0]].title << endl;
    cout << "The lowest grossing movie is "; 
    cout << movie_list[(int)lowest[0]].title << endl;
    cout << "The average gross for all 450 movies is " << mean << endl;
    
    return;
}

//Function for problem 4: the highest gross year
void highest_year(Movie movie_list[])
{
    int table[2018 - 1900];
    for (int i = 0; i < NUM_MOVIES; ++i)
    {
        table[movie_list[i].year - 1900] +=  movie_list[i].gross;
    }
    
    int highest[2] = {0, table[0]};
    for (int j = 0; j < 2018 - 1900; ++j)
    {
        if (table[j] >= highest[1])
        {
            highest[0] = j;
            highest[1] = table[j];
        }
    }
    
    int year = highest[0] + 1900;
    
    cout << "The year with the highest total gross is " << year << endl;
    
    return;
}

//Function for JFFE: movie_with_actor
void movie_with_actor(Movie movie_list[])
{
    string name;
    int count;
    cout << "Hi, please enter the name of the actor: ";
    getline(cin, name);
    
    for (int i = 0; i < NUM_MOVIES; ++i)
    {
        for (int j = 0; j < NUM_ACTORS; ++j)
        {
            if (movie_list[i].actors[j] == name)
            {
                cout << movie_list[i].title << endl;
            }
            else
            ++count;
        }
    }
    
    if (count == NUM_MOVIES * 5)
    cout << "There is no movie found with " << name << endl;
    
    return;
}

/*************************************************************
 *                          NOTE                               
 * The function below is part of the starter code and enables
 * you to read in from a file. You do not need to understand
 * the code below to complete the lab and we encourage you to
 * ignore it.  This implementation will be covered in the
 * future but is not currently required for lab or hw.
 *************************************************************/

/*  
 *   READ_MOVIE_DATA
 *   Parameters: Empty movie array
 *   Purpose: Read lists of movies data from a file and store in array
 *   Returns: Does not return anything
 *   Effects: Modifies the contents of the movies array
 */
void read_movie_data(Movie movies[NUM_MOVIES])
{
    // ifstream objects allow us to open and read data from a file
    ifstream infile;
    string   filename = "moviedata.txt";

    // open file
    infile.open(filename);

    // check if file successfully opened if it isn't the program is
    // exited immediately
    if (infile.fail())
    {
        cerr << "ERROR: Error opening file, please check file name: "
             << filename << endl;
        exit(EXIT_FAILURE);
    }

    // read through file
    for (int i = 0; i < NUM_MOVIES; i++)
    {
        getline(infile, movies[i].title);
        infile >> movies[i].year;
        infile >> movies[i].gross;
        infile.ignore();
        getline(infile, movies[i].director);

        // reads in each actors name
        for (int j = 0; j < NUM_ACTORS; j++)
        {
            getline(infile, movies[i].actors[j]);
        }
    }
}
