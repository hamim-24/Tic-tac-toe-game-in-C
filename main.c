#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

void welcome();
void heading(char str[]);
void menu();
void one_one();
void shape(char arr[3][3]);
int toss();
void winner(char arr[3][3], char str[20]);
void easy();
void medium();
void playerMove(char(arr)[3][3]);
void thinking();

void thinking()
{
  printf("\n\tCOMPUTER IS THINKING ");
  usleep(300000);
  fflush(stdout);
  for (int i = 0; i < 3; i++)
  {
    printf(".");
    usleep(350000);
    fflush(stdout);
  }
  usleep(1050000);
  fflush(stdout);
  printf("\n");
}

int toss()
{
  return rand() % 2;
}
int main()
{
  welcome();
  menu();
}

void welcome()
{
  // system("clear");
  fflush(stdout);
  char str[] = "\n\n\t\tW E L C O M E";
  for (int i = 0; i < strlen(str); i++)
  {
    printf("%c", str[i]);
    fflush(stdout);
    usleep(150000);
  }
  printf("\n");
  fflush(stdout);
  usleep(1000000);
}

void heading(char str[])
{
  // system("clear");
  fflush(stdout);
  printf("\n\n\t\tTIC TAC TEO GAME\n");
  for (int i = 0; i < 32; i++)
    printf("=");
  printf("\nType : %s\n", str);
}
void menu()
{

  heading("");
  int option;
  char *menu_option[] = {"One vs one", "Easy", "Medium", "Hard", "History", "Exit"};

  for (int i = 0; i < 6; i++)
  {
    printf("\t%d. %s\n", i + 1, menu_option[i]);
    fflush(stdout);
    usleep(100000);
  }
  printf("\nPlease select an option : ");
  scanf("%d", &option);
  fflush(stdin);

  switch (option)
  {
  case 1:
    one_one();
    break;
  case 2:
    easy();
    break;
  case 3:

    medium();
    break;
  case 4:

    printf("\n! UNDER CONSTRUCTION !");
    break;
  case 5:

    printf("\n! UNDER CONSTRUCTION !");
    break;
  case 6:
    exit(0);
    break;
  default:
    menu();
    break;
  }
  fflush(stdout);
  usleep(2000000);
  menu();
}

void shape(char arr[3][3])
{
  for (int i = 0; i < 3; i++)
  {
    printf("\n\t");
    for (int j = 0; j < 3; j++)
    {
      printf(" %c ", arr[i][j]);
      if (j < 2)
        printf("|");
    }
    if (i < 2)
      printf("\n\t---+---+---");
  }
}

void one_one()
{
  heading("One Vs One");

  char arr[3][3] = {{' ', ' ', ' '}, {' ', ' ', ' '}, {' ', ' ', ' '}};
  shape(arr);
  int row, column;
  char currentPlayer = 'O';
  printf("\n\nPlayer - '%c' \nEnter row(1,2,3) : ", currentPlayer);
  scanf("%d", &row);
  printf("Enter column(1,2,3) : ");
  scanf("%d", &column);

  while (1)
  {

    heading("One Vs One");
    if (arr[row - 1][column - 1] == ' ' && row < 4 && column < 4)
    {
      arr[row - 1][column - 1] = currentPlayer;
      currentPlayer = (currentPlayer == 'O') ? 'X' : 'O';
    }
    else
    {
      printf("!!Invalid Index!!");
    }
    shape(arr);
    winner(arr, "Easy");
    printf("\n\nPlayer - '%c' \nEnter row(1,2,3) : ", currentPlayer);
    scanf("%d", &row);
    printf("Enter column(1,2,3) : ");
    scanf("%d", &column);
  }
}

void winner(char arr[3][3], char str[20])
{
  char ch = 65;
  for (int i = 0; i < 3; i++)
  {
    for (int j = 0; j < 3; j++)
    {
      if (arr[i][j] != ' ')
        ch++;
    }
  }
  for (int i = 0; i < 3; i++)
  {
    if (arr[0][i] == arr[1][i] && arr[1][i] == arr[2][i] && arr[2][i] != ' ')
      ch = (arr[2][i] == 'X') ? 'X' : 'O';
    if (arr[i][0] == arr[i][1] && arr[i][1] == arr[i][2] && arr[i][1] != ' ')
      ch = (arr[i][1] == 'X') ? 'X' : 'O';
  }
  if (arr[0][0] == arr[1][1] && arr[1][1] == arr[2][2] && arr[1][1] != ' ')
    ch = (arr[1][1] == 'X') ? 'X' : 'O';
  if (arr[0][2] == arr[1][1] && arr[1][1] == arr[2][0] && arr[1][1] != ' ')
    ch = (arr[1][1] == 'X') ? 'X' : 'O';
  if (ch == 74)
  {
    printf("\n\nMatch Draw");
    fflush(stdout);
    usleep(2000000);
    menu();
  }
  if (ch == 'X')
  {
    printf("\n\nWinner - X");
    fflush(stdout);
    usleep(2000000);
    menu();
  }
  else if (ch == 'O')
  {
    printf("\n\nWinner - O");
    fflush(stdout);
    usleep(2000000);
    menu();
  }
}

void easy()
{
  heading("Easy");
  printf("Press enter to toss.");
  getchar();
  int t = toss();
  char arr[3][3] = {{' ', ' ', ' '}, {' ', ' ', ' '}, {' ', ' ', ' '}};
  if (t == 0)
  {
    playerMove(arr);
  }
  while (1)
  {
    winner(arr, "Easy");
    thinking();
    heading("Easy");
    while (1)
    {
      int c_row = rand() % 3;
      int c_col = rand() % 3;
      if (arr[c_row][c_col] == ' ')
      {
        arr[c_row][c_col] = 'O';
        // printf("-%d-%d-%d-", t, c_row, c_col);
        break;
      }
    }
    playerMove(arr);
  }
}

void medium()
{
  char arr[3][3] = {{' ', ' ', ' '}, {' ', ' ', ' '}, {' ', ' ', ' '}};
  int t = toss();
  heading("Medium");
  printf("Press enter to toss.\n");
  getchar();

  if (t == 0)
  {
    playerMove(arr);
  }
  while (1)
  {
    winner(arr, "Medium");
    thinking();
    heading("Medium");

    while (1)
    {
      int c_row = rand() % 3;
      int c_col = rand() % 3;
      int flag = 0;
      if (arr[c_row][c_col] == ' ')
      {
        for (int i = 0; i < 3; i++)
        {
          if (arr[0][i] == arr[1][i] && arr[1][i] == arr[2][i] && arr[2][i] != ' ')
          {
            arr[2][i] = 'O';
            flag = 1;
          }
          else if (arr[i][0] == arr[i][1] && arr[i][1] == arr[i][2] && arr[i][1] != ' ')
          {
            arr[2][i] = 'O';
            flag = 1;
          }
          break;
        }
        if (flag == 1)
        {
          break;
        }
        if (arr[0][0] == arr[1][1] && arr[1][1] == arr[2][2] && arr[1][1] != ' ')
          {arr[1][1] == 'O';
        break;}
        if (arr[0][2] == arr[1][1] && arr[1][1] == arr[2][0] && arr[1][1] != ' ')
        arr[c_row][c_col] = 'O';
        // printf("-%d-%d-%d-", t, c_row, c_col);
        break;
      }
    }
    playerMove(arr);
  }
}

void playerMove(char(arr)[3][3])
{
  int row, column;
  char currentPlayer = 'X';

  while (1)
  {
    shape(arr);
    winner(arr, "Easy");

    printf("\n\nPlayer - '%c' \nEnter row(1,2,3) : ", currentPlayer);
    scanf("%d", &row);
    printf("Enter column(1,2,3) : ");
    scanf("%d", &column);
    if (arr[row - 1][column - 1] == ' ' && row < 4 && column < 4)
    {
      arr[row - 1][column - 1] = currentPlayer;
      break;
    }
    else
    {
      printf("-%c-", arr[row - 1][column - 1]);
      heading("Easy");
      printf("!!Invalid Index!!");
    }
  }
}