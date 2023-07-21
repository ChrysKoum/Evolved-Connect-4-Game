static int ifFirst=1,playerNum=0;
#include"board.h"
#include<stdlib.h>
#include<stdio.h>
/*
Your job is to implement the player() function, so that everytime it returns a column number to play.
In every turn it takes the entire board struct pointer:
*/
typedef struct Board{
    int rows;
    int columns;
    int** board;
}b;
/*
Board.board is a two dimensional array declared somewhat like this: Board.board[rows][columns]
*/
int CheckAdvancedMove(const Board* b,int id,int counterlimit){
		printf("1");
		int idef=1,jdef_start,jdef_end,k;
        int tempscore = 0;
        int maxv = 0, maxr=0 ;
		int movev=-1 ,mover=-1 ,moved1=-1 ,moved2=-1;
		int maxd1=0 ,maxd1_a=0 ,maxd1_b=0 ;
		int maxd2=0 ,maxd2_a=0 ,maxd2_b=0 ;
		int blank,tempscoreb,jblank;
		//checking for vertical numbers in a row
		printf("1");
		for(int j = 0; j< b->columns; j++){
        for(int i = 0; i< b->rows; i++){
            if(b->board[i][j] == id && i <= b->rows - 2){
							if(tempscore == 0 && i>0){
											idef=i;
										}
                tempscore = 1;
                i++;
                while(i < b->rows && b->board[i][j] == id){
                    tempscore++;
                    i++;
                }
                if(tempscore == 1){
                    tempscore = 0;
                }
						}
            if(tempscore > maxv){
              maxv = tempscore;
						} 
						if(b->board[idef-1][j]==0 && maxv>=counterlimit){ 
						movev=j;
						printf("put chips up");
						j=b->columns;
						break;
					}
            tempscore = 0;
        }
    }
   //diagonaly from top-left to bottom-right
		tempscoreb = 0;
		blank=0;
		printf("2");
		int temp_i_start,temp_i_end;
		int temp_j_start,temp_j_end; 
		int test=0;
    for(int i = 0; i < b->rows; i++){

        for(int tempi = i, tempj = 0; (tempi < b->rows) && (tempj < b->columns); tempi++, tempj++){

            if(b->board[tempi][tempj] == id && tempi <= b->rows - 2 && tempj <= b->columns - 2){
                tempscore = 1;
                tempi++;
                tempj++;
                while(tempi < b->rows && tempj < b->columns && b->board[tempi][tempj] == id){
										if(b->board[tempi][tempj] == id && blank!=2){
												tempscoreb++;
												if(b->board[tempi][tempj] == 0){
													if(blank==0){
														tempscoreb++;
														jblank=tempj;
													}
													blank++;
												}
										}
										if(b->board[tempi][tempj] == id && tempscore == 0){
											temp_i_start=tempi;
											temp_j_start=tempj;
										}
									 tempscore++;
                   tempi++;
                   tempj++;
                }
                if(tempscore == 1){
                    tempscore = 0;
                }
								if(tempscoreb<counterlimit+1){
										tempscoreb=0;
								}
								if(tempscoreb > tempscore && tempscore!=0){
									moved1= jblank;
									maxd1_b=tempscoreb;
									break;
								}
            if(tempscore > maxd1_a){
                maxd1_a = tempscore;
            		temp_i_end=tempi;
								temp_j_end=tempj;
						}
                tempscore = 0;
								tempscoreb=0;
            }
        }
    }
    for(int j = 1; j < b->columns; j++){
        for(int tempi = 0, tempj = j; tempi < b->rows && tempj < b->columns; tempi++, tempj++){
            if(b->board[tempi][tempj] == id && tempi <= b->rows - 2 && tempj <= b->columns - 2){
                tempscore = 1;
                tempi++;
                tempj++;
                while(tempi < b->rows && tempj < b->columns && b->board[tempi][tempj] == id){
									if(b->board[tempi][tempj] == id && blank!=2){
												tempscoreb++;
												if(b->board[tempi][tempj] == 0){
													if(blank==0){
														tempscoreb++;
														jblank=tempj;
													}
													blank++;
												}
										}
                    tempscore++;
                    tempi++;
                    tempj++;
                }
                if(tempscore == 1){
                    tempscore = 0;
                }
								if(tempscoreb<counterlimit+1){
										tempscoreb=0;
									}
								if(tempscoreb > tempscore && tempscore!=0){
									moved1= jblank;
									maxd1_b=tempscoreb;
									break;
								}
            if(tempscore > maxd1_b && maxd1_b > maxd1_a){
              	temp_i_end=tempi;
								temp_j_end=tempj;
								temp_i_start= temp_i_end - (tempscore-1);
								temp_j_start= temp_j_end - (tempscore-1);
								maxd1_b = tempscore;
								test=1;
            }
                tempscore = 0;
								tempscoreb = 0;
            }
        }
    }
		if(test)
			maxd1=maxd1_b;
		else{
			maxd1=maxd1_a;
		}
		test=0;
		if(moved1>-1){
			for(int i = 0; i< b->rows; i++){
					for(int j = 0; j< b->columns; j++){
						if(temp_i_start>0){
							if((temp_j_start>0 && b->board[temp_i_start][temp_j_start-1] !=0 ) &&  (b->board[temp_i_start-1][temp_j_start-1] == 0)){              //diagonally top-left chip
								moved1=temp_j_start-1;
								printf("\n diagonally up-left chip\n");
			 	    		break;
							}
						}
					if(temp_j_end<(b->columns-1) && temp_i_end<(b->rows-1)) {   //diagonally right-bottom to chip
						k=2;
						if(temp_i_end==(b->rows-2))
							k=1;
						if((b->board[temp_i_end+k][temp_j_end+1] != 0 || k==1)  &&  (b->board[temp_i_end+1][temp_j_end+1] == 0  )){
							moved1=temp_j_end+1;
							printf("\n diagonally right-down to chip\n");
							break;
						}
			  	}
				}
			}
		}
    //diagonaly from top right to bottom left
		tempscoreb = 0;
		blank=0;
    for(int i = 0; i < b->rows; i++){
       //int tempi = i;
       //int tempj = 0;
        for(int tempi = i, tempj = b->columns - 1; (tempi < b->rows) && (tempj >= 0); tempi++, tempj--){

            if(b->board[tempi][tempj] == id && tempi <= b->rows - 2 && tempj >= 1){
                tempscore = 1;
                tempi++;
                tempj--;
                while(tempi < b->rows && tempj >= 0 && b->board[tempi][tempj] == id){
										if(b->board[tempi][tempj] == id&& blank!=2){
												tempscoreb++;
												if(b->board[tempi][tempj] == 0){
													if(blank==0){
														tempscoreb++;
														jblank=tempj;
													}
													blank++;
												}
										}
											if(b->board[tempi][tempj] == id && tempscore == 0){
											temp_i_start=tempi;
											temp_j_start=tempj;
										}
                   tempscore++;
                   tempi++;
                   tempj--;
                }

                if(tempscore == 1){
                    tempscore = 0;
                }
								if(tempscoreb<counterlimit+1){
										tempscoreb=0;
									}
								if(tempscoreb > tempscore && tempscore!=0){
									moved2= jblank;
									maxd2_b=tempscoreb;
									break;
								}
                //printf("%d\n", tempscore);
         		    if(tempscore > maxd2_a){
									temp_i_end=tempi;
									temp_j_end=tempj;
            	    maxd2_a = tempscore;
           		  }
                tempscore = 0;
								tempscoreb =0;
            }
        }
				if(mover>-1){
	  			i = b->rows;
  			 	break;
				}
    }
    for(int j = 0; j < b->columns - 1; j++){
     for(int tempi = 0, tempj = j; tempi < b->rows && tempj > 0; tempi++, tempj--){
            if(b->board[tempi][tempj] == id && tempi <= b->rows - 2 && tempj >= 1){
                tempscore = 1;
                tempi++;
                tempj--;
                while(tempi < b->rows && tempj >= 0 && b->board[tempi][tempj] == id){
										if(b->board[tempi][tempj] == id && blank!=2){
												tempscoreb++;
												if(b->board[tempi][tempj] == 0){
													if(blank==0){
														tempscoreb++;
														jblank=tempj;
													}
													blank++;
												}
										}
                    tempscore++;
                    tempi++;
                    tempj--;
                }
                if(tempscore == 1){
                    tempscore = 0;
                }
								if(tempscoreb<counterlimit+1){
										tempscoreb=0;
									}
							}
							if(tempscoreb > tempscore && tempscore!=0){
								moved2= jblank;
								maxd2_b=tempscoreb;
								break;
							}

            if(tempscore > maxd2_b){
								temp_i_end=tempi;
								temp_j_end=tempj;
								temp_i_start= temp_i_end - (tempscore-1);
								temp_j_start= temp_j_end - (tempscore-1);
								test=1;
                maxd2_b = tempscore;
            }
                tempscore = 0;
								tempscoreb = 0;
            }
					if(mover>-1){
	  				j = b->columns;
  				 	break;
					}
			}
		if(test){
			maxd2=maxd2_b;
		}
		else{
			maxd2=maxd2_a;
		}
		if(moved2==-1){
			for(int i = 0; i< b->rows; i++){
					for(int j = 0; j< b->columns; j++){
						if(temp_i_start>0){
							if((temp_j_start<(b->columns-1) && b->board[temp_i_start][temp_j_start+1] !=0)  &&  (b->board[temp_i_start-1][temp_j_start+1] == 0)){ //diagonally top-right chip
								moved2=temp_j_start+1;
								printf("diagonally up-right chip");
								break;
				 	  	}
						}
						if(temp_j_end>0 && temp_i_end<(b->rows-1)) {
							//diagonally left-bottom to chip
								k=2;
							if(temp_i_end==(b->rows-2))
								k=1;
							if((b->board[temp_i_end+k][temp_j_end-1] != 0 || k==1)  &&  (b->board[temp_i_end+1][temp_j_end-1] == 0  )){
								moved2=temp_j_end-1;
								printf("diagonally left-bottom to chip");
								break;
				 		  }
						}
					}
			}
		}
			//    checking for sequential no's in a row
			int tjdef_start;
			tempscoreb = 0;
			blank=0;
			for(int i = 0; i< b->rows; i++){
					for(int j = 0; j< b->columns; j++){
							if(b->board[i][j] == id && j <= b->columns - 2){
								if(tempscore == 0 && j>0){
										tjdef_start=j;
									}
									tempscore = 1;
									j++;
									while(j < b->columns && b->board[i][j] == id){
											tempscore++;
											if(b->board[i][j] == id && blank!=2){
												tempscoreb++;
												if(b->board[i][j] == 0){
													if(blank==0){
														tempscoreb++;
														jblank=j;
													}
													blank++;
												}
											}
											j++;
									}
									if(tempscore == 1){
											tempscore = 0;
									}
									if(tempscoreb<counterlimit+1){
										tempscoreb=0;
									}
							}
							if(tempscoreb > tempscore && tempscore!=0){
								mover=jblank;
								maxr=4;
								break;
							}
							else if(tempscore > maxr){
									jdef_end=j;
									maxr = tempscore;
									jdef_start=tjdef_start;
							}
							if(maxr>=counterlimit){
								k=1;
								if(i==b->rows-1)
									k=0;
								if((b->board[i][jdef_end+1] == 0)  && (b->board[i+k][jdef_end+1] != 0 || k==0) && (jdef_end<(b->columns-1))){
									mover=jdef_end+1;
									printf("next to the chip right ");
									break;
								}
								else if((b->board[i][jdef_start-1] == 0) && (b->board[i+k][jdef_start-1] != 0 || k==0) ){
									mover=jdef_start-1;
									printf("next to the chip left ");
									break;
								}
							}
							tempscore = 0;
							tempscoreb = 0;
					}
					if(mover>-1){
	  				i = b->rows;
  				 	break;
					}
			}
	printf("\n maxr=%d maxv=%d maxd1=%d maxd2=%d\n",maxr,maxv,maxd1,maxd2);
	if(counterlimit>maxr && counterlimit>maxv && counterlimit>maxd1 && counterlimit>maxd2){
  	return -1;
	}
	if(maxv>=maxr && maxv>=maxd1 && maxv>=maxd2 && movev>-1){
		printf("\nreturn 1\n");
		return movev;
	}
	else if(maxd1 >= maxd2 && maxd1 >= maxr && moved1>-1){
		printf("\nreturn 2\n");
		return moved1;
	}
	else if(maxd2 >= maxr && moved2>-1){
		printf("\nreturn 3\n");
		return moved2;
	}
	else if(mover>-1){
		printf("\nreturn 4\n");
		return mover;
	}
	else return -1;
}

extern int player(const Board* b){
	int ret_move , move=-1 , i , j , k , Finalmove ;
	int *maxd ,moved=-1;
	int *maxaa ,moveaa=-1;
	if(playerNum==0){
    // what is my player number?
	for(i=0;i<b->rows;i++)
    for(j=0;j<b->columns;j++)
			if(b->board[i][j]>playerNum)
					playerNum=b->board[i][j]+1;
	}
	if(playerNum==0){
		playerNum++;
        //printf("\nplayerNum=%d\n",playerNum);
			for(i=0;i<b->rows;i++){
    		for(j=0;j<b->columns;j++){
	 				if((j==(b->columns/2)) && (b->board[i][j] == 0) && (i==b->rows-1)){
						move = j;
						ifFirst=0;
						i = b->rows;
					  j = b->columns;
			    }
				}
			}
	}
	int counterlimit=3;
	if(b->rows==4){
		counterlimit=2;
	}
	if(ifFirst){
	 move=b->columns/2+1;
	 ifFirst=0;
	}             //for attack to add 1 chips
	printf("\nmove= %d\n",move);
	if (move == (-1)){
		printf("2\n");
		move=CheckAdvancedMove(b,1,counterlimit);
		printf("\nmoved= %d\n",move);
	}
	if (move == -1){
		printf("2\n");
		move=CheckAdvancedMove(b,playerNum,counterlimit);
		printf("\nmoveaa= %d\n",move);	
	}
	if((moved>-1 || moveaa>-1)){
		if(maxd<maxaa){
			move=moved;			
		}
		else{
			move=moveaa;
		}
	}
	printf("\nmove aattack= %d\n",move);
	printf("\ncheck after \n");
    //checking for enemys chips streaks in a row
  
	if(move == -1){              //for attack to add 1 chips  
  	for(i=0;i<b->rows;i++){
			for(j=0;j<b->columns;j++){
				if(b->board[i][j] == playerNum){
		   		if(i>0 && b->board[i-1][j]==0){     //put chips up 
			    	move=j;
						printf("put chips up");
			    	break;
					}      
				k=1;             //next to the chip
				if(i==b->rows-1)
					k=0;
				if((b->board[i][j+1] == 0)  && (b->board[i+k][j+1] != 0 || k==0) && j<(b->columns-1)){
					move=j+1;
					printf("next to the chip right ");
					break;
	    	}
		    else if((b->board[i][j-1] == 0) && (b->board[i+k][j-1] != 0 || k==0) && j>0){
		    	move=j-1;
					printf("next to the chip left ");
		    	break;
				}
				if(i>0){//diagonaly from top-left to bottom-right
					if((j<(b->columns-1) && b->board[i][j+1] !=0)  &&  (b->board[i-1][j+1] == 0)){ //diagonally top-right chip
						move=j+1;
						printf("diagonally up-right chip");
						break;
				  }
					if((j>0 && b->board[i][j-1] !=0 ) &&  (b->board[i-1][j-1] == 0)){              //diagonally top-left chip
						move=j-1;
						printf("diagonally up-left chip");
			 	    break;
					}
				}
				if(j>0 && i<(b->rows-1)) {   //diagonally left-bottom to chip
       	  k=2;
			  	if(i==(b->rows-2))
				 		k=1;
				  if((b->board[i+k][j-1] != 0 || k==1)  &&  (b->board[i+1][j-1] == 0  )){
						move=j-1;
						printf("diagonally left-bottom to chip");

		    		break;
				  }
				}
				if(j<(b->columns-1) && i<(b->rows-1)) {   //diagonally right-bottom to chip
       	  k=2;
				  if(i==(b->rows-2))
					 	k=1;
			  	if((b->board[i+k][j+1] != 0 || k==1)  &&  (b->board[i+1][j+1] == 0  )){
						move=j+1;
		    		printf("diagonally right-down to chip\n");
					break;
				 }
			  }
				}		
			}
			if(move>-1){
	  		i = b->rows;
  		 	break;
			}	
		}
	}
	printf("\nafter attack move=%d\n",move);
	if(move==-1)
  	for(i=0;i<b->rows;i++)
			for(j=0;j<b->columns;j++)
					if(b->board[i][j] == 0){
						move=j;
						printf("if not attack just put something\n");
						i = b->rows;
						j = b->columns;
					}
	putchar('\n');
	
	Finalmove=move;	
  return Finalmove;
}
