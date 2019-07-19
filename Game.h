#include"Movie.h"

void gotoxy(int x,int y)
{
    printf("%c[%d;%df",0x1B,y,x);
}

class Game:public Movie{
  vector<bool>alphabet;
  string bolly;
  int bollywood;
public:
  Game():Movie()
  {
    alphabet=vector<bool>(26,false);
    bollywood=9;
    bolly="BOLLYWOOD";
  }
  Game(const char* filename,int Moviesize):Movie(Moviesize)
  {
    getList(filename);
    alphabet=vector<bool>(26,false);
    bollywood=9;
    bolly="BOLLYWOOD";
  }
  void GameOn(string,int);
  bool displayPage(string);
  void clearAll();
  void startGame();
  void checkCharPresence(string,char);
  void verdict(int,string);
  void initialize();
  void addItems();
};

void Game::initialize()
{
  printf("\033c");
  cout<<"Enter string for Game Name\n";
  cin>>bolly;
  Capitalize(bolly);
  bollywood=bolly.length();
  addItems();
}

void Game::addItems()
{
  char tempCh;
  string Item;
  do{
    printf("\033c");
    cout<<"Please Add some Items in your list\n";
    cout<<"Item Name:  ";
    getline(cin,Item);
    getline(cin,Item);
    Movie::addItems(Item);
    cout<<"\n\nYour list is: \n";
    display();
    cout<<"\n\nwants to add more press 'y'\n";
    cout<<"wants to play the game press ESC\n";
    cin>>tempCh;
    if(tempCh==27)
    {
      startGame();
      return;
    }
  }while(toupper(tempCh)=='Y');
}

void Game::verdict(int MovieNo,string comment)
{
  printf("\033c");
  gotoxy(10,10);
  cout<<comment;
  gotoxy(10,15);
  string MovieName=getMovieName(MovieNo);
  Capitalize(MovieName);
  cout<<"Movie Name is: "<<MovieName<<endl;
  char ch;
  gotoxy(10,20);
  cout<<"Look like! You want to play more press ESC:  ";
  cin>>ch;
  if(ch==27)
  {
    clearAll();
    startGame();
  }
}

void Game::clearAll()
{
  for(int i=0;i<26;i++)
    alphabet[i]=false;
  bollywood=bolly.length();
}

void Game::checkCharPresence(string MovieName,char MovieNameCharacter)
{
  for(int i=0;i<MovieName.length();i++)
      if(MovieName[i]==MovieNameCharacter)
      return;

  bollywood--;
}

void Game::GameOn(string MovieName,int MovieNo)
{
  bool flag=true;
  char MovieNameCharacter;
  while(bollywood>0){
    system("clear");
    //display(MovieName);
    flag=displayPage(MovieName);
    if(!flag)
    break;

    cin>>MovieNameCharacter;
    try{
      if((!(MovieNameCharacter>='a'&&MovieNameCharacter<='z'))&&(!(MovieNameCharacter>='A' &&
       MovieNameCharacter<='Z'))&&(MovieNameCharacter!=27))
       {
         throw MovieNameCharacter;
       }
       if(MovieNameCharacter==27)
       {
         clearAll();
         startGame();
       }
       MovieNameCharacter=toupper(MovieNameCharacter);
       alphabet[MovieNameCharacter-'A']=true;
       checkCharPresence(MovieName,MovieNameCharacter);
    }
    catch(char MovieNameCharacter)
    {
      cout<<"\""<<MovieNameCharacter<<"\""<<"is not an alphabet.";
    }
  }
  clearAll();
  string comment;
  if(!flag)
  comment="Congo You Guess it right!!";
  else
  comment="Sorry!! You Didn't Guess it right";
  verdict(MovieNo,comment);
}

bool Game::displayPage(string MovieName)
{
  gotoxy(10,5);
  int n=bolly.length();
  for(int i=0;i<n;i++)
  {
    if(n-i-bollywood>0)
    cout<<" "<<"\t";
    else
    cout<<bolly[i]<<"\t";
  }
  bool flag=false;
  for(int i=0;i<MovieName.length();i++)
  {
    if(i%7==0)
    gotoxy(10,10+3*(i/7));

    if(alphabet[MovieName[i]-'A'])
    cout<<MovieName[i]<<"\t";
    else{
    cout<<"_\t";
    flag=true;
    }
  }
  gotoxy(2,25);
  cout<<"Want to RESTART the game press ESC ";
  gotoxy(10,22);
  cout<<"enter a character:  ";
  return flag;
}

void Game::startGame()
{
  try{
    if(getMovieSize()<=0)
    throw "Your List is empty.Please add some items in list";

  int MovieNo=(rand()%getMovieSize());
  string MovieName=getMovieName(MovieNo);
  MovieName=MovieName-' ';
  Capitalize(MovieName);
  GameOn(MovieName,MovieNo);
  }
  catch(const char* error)
  {
    cout<<error;
  }
}
