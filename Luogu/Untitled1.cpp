#include<stdio.h>
#include<stdlib.h>
#include<windows.h>
#include<conio.h>

/*
    	《反弹球消砖块》	by：你最珍贵
    	
			 ———————————
			|控制信号： | 左 | 右 |
			 ——————————— 
			|    键盘： |  j |  l | 
			 ———————————
	 
	 1.击中上方方块'H'，分数加1  
	 2.下方控制线没有接到小球时，游戏结束 

*/

void HideCursor(){	//隐藏光标位置 ,这个函数复制代码就行 
	CONSOLE_CURSOR_INFO cursor_info={1,0}; 
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE),&cursor_info);
}
void gotoxy(int x,int y){	//把光标放在（0,0）位置 ,这个函数复制代码就行
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD pos;
	pos.X = x;
	pos.Y = y;
	SetConsoleCursorPosition(handle,pos);
} 

int IsEnd;//是否结束 
int interface_x,interface_y;//界面行数、列数 
int block_y;//砖块列位置 
int ctrlline_width,ctrlline_left,ctrlline_right;//控制线的左列数,宽度,右列数 
int ball_x,ball_y;//小球位置 
int ballv_x,ballv_y; //小球行列速度(1为正方向-1为反方向)
int scores;//分数 
int ballv_num;//小球速度的慢速变量，数值越大越慢 
int ballv_num_i;//小球慢速变量值的循环变量 

void startup(){	//【数据初始化】 
	HideCursor();//不显示光标 
	IsEnd = 0;
	interface_x = 22;
	interface_y = 30;
	block_y = rand()%(interface_y-6)+2; 
	ctrlline_width=8;
	ctrlline_left=(interface_y-ctrlline_width-2)/2+1+1;//控制线最左列位置 
	ctrlline_right=ctrlline_left+ctrlline_width-1; 
	ball_x=interface_x-1;
	ball_y=ctrlline_left+ctrlline_width/2; 
	ballv_x=1;
	ballv_y=1;
	scores=0;
	ballv_num=3; 
	ballv_num_i=1; 
}
void show_begin(){//【初始页面展示】 
	int i,j;
	int start=0;
	char input;
 	while(!start){
 		gotoxy(0,0);//每次输出页面把鼠标放回(0,0) 
 		for(i=1;i<=interface_x/2-4;i++) printf("\n"); 
		for(i=1;i<interface_y/2-8;i++) printf(" ");
		printf("《反弹球消砖块》\n\n");
		for(i=1;i<interface_y/2-9;i++) printf(" ");
		printf("请按任意键开始游戏\n\n");
		for(i=1;i<=interface_x/2-6;i++) printf("\n");
		if(kbhit()){
			input = getch();
			if(input) start=1;
		}
	}
} 
void show(){	//【显示画面】 
	gotoxy(0,0);//每次输出页面把鼠标放回(0,0) 
	int i,j;
	for(i=1;i<=interface_y/2-8;i++) printf(" ");
	printf("《反弹球消砖块》") ;
	for(i=1;i<=interface_y/2-8-8;i++) printf(" ");
	printf("分数:%3d\n",scores);
	for(i=1;i<=interface_x;i++){
		printf(" ");//使屏幕对称加的空格 
		for(j=1;j<=interface_y;j++){			
			if(j==1||j==interface_y){	//边框 
				printf("|");
			}else if(i==interface_x){	//边框 
				printf("_");
			}else if(i==1){		//上边界 
				printf("V");
			}else if(i==interface_x-1&&(j>=ctrlline_left&&j<=ctrlline_right)){	//控制线 
				printf("*");
			}else if(i==2&&(j>=block_y&&j<=block_y+4)){		//砖块 
				printf("H");
			}else if(i==ball_x&&j==ball_y){		//反弹球 
				printf("O");
			}else printf(" ");	//什么也不是的位置输出空格 
		}
		printf("\n");
	}
	
}
void update_outinput(){	//【与输入无关的更新】 
	ballv_num_i= (ballv_num_i==ballv_num)?1:ballv_num_i+1;//ballv_num_i一次从{1到ballv_num}循环，当ballv_num_i为最大时才更新球的位置，此目的是减速 
	if(ballv_num_i==ballv_num){
		if(ball_y==2||ball_y==interface_y-1){//判断是否到左右边界 
			ballv_y *= -1;
		}
		if(ball_x==2){//判断是否到上边界
			if(ball_y>=block_y&&ball_y<=block_y+4){//判断在上边界有无消去砖块 
				block_y = rand()%(interface_y-6)+2;//消去则砖块位置重置 
				scores++;//分数加1
				printf("\a");//提示音 
			}
			ballv_x *= -1;//不论是否碰砖块，都要反弹 
		}
		if(ball_x==interface_x-1){//判断是否下边界接住小球了，若接住反弹，否则结束游戏 
			if(ball_y>=ctrlline_left && ball_y<=ctrlline_right){
				ballv_x *= -1;
			}else{
				IsEnd = 1;
			}
		}
		ball_x += ballv_x;
		ball_y += ballv_y;
	}	
}
void update_input(){//【与输入有关的更新】 
	char input;
	if(kbhit()){
		input = getch();
		if( input == 'j'){//输入“j”下方控制线左移 
			ctrlline_left= (ctrlline_left==2)?2:ctrlline_left-1;
			ctrlline_right= ctrlline_left+ctrlline_width-1;
		}else if( input == 'l'){//输入“l”下方控制线右移 
			ctrlline_left= (ctrlline_left==interface_y-ctrlline_width)?\
interface_y-ctrlline_width:ctrlline_left+1;
			ctrlline_right= ctrlline_left+ctrlline_width-1;
		}
	}
}
void show_end(){//【显示失败界面】 
	system("cls"); 
	printf("\n\n\n\n\n\ngame over!\n\n\n\n\n\n\n\n\n\n\n\n\n");	
	system("pause");//暂停 
	system("pause");//暂停
}

int main(){
	startup();	//数据初始化
	show_begin();//初始页面 
	while(!IsEnd){	//游戏循环执行 
		show();	// 显示画面 
		update_outinput();	//与输入无关的更新 
		update_input();	//与输入有关的更新 
	}
	show_end(); //显示失败界面 
	return 0;
}
