#include<bits/stdc++.h>
using namespace std;

class Movie{
  vector<string>movie;
  int MovieSize;
public:
  Movie()
  {
    MovieSize=0;
    movie=vector<string>();
  }
  Movie(int Moviesize)
  {
    MovieSize=Moviesize;
    movie=vector<string>(Moviesize);
  }
  void getList(const char* );
  void display();
  void display(string);
  friend string operator-(string &,char);
  void Capitalize(string &);
  string getMovieName(int);
  int getMovieSize();
  void addItems(string);
};

void Movie::addItems(string items)
{
  movie.push_back(items);
  MovieSize++;
}

int Movie::getMovieSize()
{
  return MovieSize;
}

void Movie::getList(const char* filename)
{
  ifstream infile;
  infile.open(filename);
  for(int i=0;i<MovieSize;i++)
  getline(infile,movie[i]);
  infile.close();
}

string Movie::getMovieName(int MovieNo)
{
  //cout<<MovieNo<<endl;
  //cout<<movie[MovieNo]<<endl;
  return movie[MovieNo];
}

void Movie::Capitalize(string & MovieName)
{
    transform(MovieName.begin(), MovieName.end(), MovieName.begin(), ::toupper);
}

void Movie::display(string MovieName)
{
  cout<<MovieName<<endl;
}

void Movie::display()
{
  for(int i=0;i<MovieSize;i++)
  cout<<movie[i]<<endl;
}

string operator-(string MovieName,char removingChar)
{
   string newMovieName="";
   int index=0;
   while(MovieName[index])
   {
     if(MovieName[index]!=removingChar)
      newMovieName=newMovieName+MovieName[index];
     index++;
   }
   return newMovieName;
}
