// #include<bits/stdc++.h>   //iostream, conio.h, windows.h

#include<iostream>
#include<conio.h>
#include<windows.h>
using namespace std;

enum Direction{STOP=0, LEFT, RIGHT, UP ,DOWN};
Direction dir;
bool gameOver;
const int height= 20;
const int width= 20 ;
int headX, headY, fruitX, fruitY, score;
int tailX[100], tailY[100];  ///array
int tail_len;

void setup();
void draw();
void input();
void logic();



int main(){
    char start;
    cout<<"\t---------------------------------------"<<endl;
    cout<<"\t\t ::SNAKE KING::"<<endl;
    cout<<"\t---------------------------------------"<<endl;
    cout<<"\tPress 's' to start:";
    cin>> start;
    if (start== 's'){
        //  cout<<"\tGame Start";
        setup();
       while(!gameOver){
          draw();
          input();
          logic();
          Sleep(200);   //function of windows.h (used to slow down the loop)
          system("cls"); // used to remove the last screen and we can print our new screen in same position
            //  gameOver=true;
       }
    }

    // return 0;

}

void setup(){
    gameOver= false;
    dir= STOP;
    headX  = width/2;   // to place snake in the center
    headY = height/2;
    fruitX = rand()%width ;   // to place fruit at any random places
    fruitY = rand()%height ;
    score=0;
}
void draw(){
    system("cls");
    //upper border
   cout<<"\t\t";
   for(int i=0;i<width-8;i++){
    cout<<"||";
   }

   cout<<endl;

   // for snake,fruit,space and side bars
   for(int i=0;i< height;i++){
    for(int j =0;j<width;j++){
        //left border
        if(j==0){
            cout<<"\t\t||";
        }
        //snake head
        if(i==headY && j== headX){
            cout<<"O";
        }
        //fruit 
        else if (i== fruitY && j== fruitX){
            cout<<"*";
        }
        //space and smake tail
        else{

            bool print =false;
            //tail
            for( int k =0; k < tail_len; k++){
                 if (tailX[k]== j && tailY[k]==i){
                    cout<<"o";
                    print= true;
                 }
            }
            //space
              if (!print){
                cout<<" ";
              }
        }

        //right border
        if (j == width-1){
            cout<<"||";
        }
    }
    cout<<endl;}
    //lower border
    cout<<"\t\t";
    for(int i=0;i <width-8;i++){
        cout<<"||";
    }
    cout <<endl;

    cout<<"\t\t\tscore:" << score<< endl;

   }

void input(){
    if (_kbhit()) // return the true value until aother key is pressed..mtlb ki vo left or right direction me hi chlta rhega until another command
      switch(getch()){
        case 'a':
        dir = LEFT;
        break;
        case 'd':
        dir=RIGHT;
        break;
        case  'w':
        dir=UP;
        break;
        case 's':
        dir = DOWN;
        break;
        default:
        break;

      }


}
void logic(){

    //tail
    int prevx= tailX[0];
    int prevy = tailY[0];
    int prev2x, prev2y;
    tailX[0]= headX;
    tailY[0]= headY;
    for (int i =1; i < tail_len;i++){
        prev2x = tailX[i];
        prev2y= tailY[i];
        tailX[i] = prevx;
        tailY[i] = prevy;
        prevx=prev2x;
        prevy=prev2y;
    }

// direction of tail
switch (dir){
     case LEFT:
     headX--;
     break;
     case RIGHT:
     headX++;
     break;
     case UP:
     headY--;
     break;
     case DOWN:
     headY++;
     break;
     default:
     break;

}

//touch wall (snake will pass the wall and appear on the other side of wall)

 if (headX>=width){
    headX=0;

 }
 else if ( headX< 0){
    headX= width -1;


 }
 if(headY>=height){
    headY=0;
 }
 else if (headY<0){
    headY= height-1;
 }
// if snake strike with itself
 for( int i =0;i<tail_len;i++){
    if ( tailX[i] == headX && tailY[i]== headY){   //compare two value of index and if same then the game will be over

         gameOver=true;

    }
 }

// snake eat fruit  ( happen when the axis of fruit and snake head will be same)

 if ( headX == fruitX && headY == fruitY){
    score+=20;
    fruitX = rand()%width;   //new fruit will generate randomlly at any  point
    fruitY = rand()%height;
    tail_len++;
     }

}


