#include <stdio.h>
#include <assert.h>

int pos[1000000][2];

int main(){
  int n,m,i,j,k,moves,in_rep;
  scanf("%d %d",&n,&m);

  int apples = n*m-1;

  for(i=0;i<apples;i++){
    scanf("%d %d",&pos[i][0],&pos[i][1]);
  }
  int minmum = n>m?m:n;
  if(apples == 0){
    printf("0\n");
  }
  else if(minmum == 1){
    moves = (apples+1)*n*m;
    assert(moves <= 900000);
    printf("%d\n",moves);
    int plays[moves];
    int move = 0;
    if(n == 1){
      for(i=0;i<=apples;i++){
	for(j=0;j<m;j++){
	  plays[move++] = 3;
	}
      }
      for(i=0;i<move-1;i++){
	printf("%d ",plays[i]);
      }
      printf("%d\n",plays[move-1]);
    }
    else{
      for(i=0;i<=apples;i++){
	for(j=0;j<n;j++){
	  plays[move++] = 1;
	}
      }
      for(i=0;i<move-1;i++){
	printf("%d ",plays[i]);
      }
      printf("%d\n",plays[move-1]);
    }
  }
  else{
    moves = n*m*(apples+1);
    assert(moves <= 900000);

    char board[n][m];
    int plays[moves];    
    for(i=0;i<n;i++)
      for(j=0;j<m;j++)
	board[i][j] = 'O';    
    int move = 0;
    if(n%2 == 0){
      for(i=0;i<=apples;i++){

	for(j=0;j<m-1;j++){
	  plays[move++] = 3;
	}
	in_rep = (n-2)/2;
	for(k = 0; k < in_rep; k++){
	  plays[move++] = 1;
	  for(j=0;j<m-2;j++){
	    plays[move++] = 2;
	  }
	  plays[move++] = 1;
	  for(j=0;j<m-2;j++){
	    plays[move++] = 3;
	  }
	}

	plays[move++] = 1;
	for(j=0;j<m-1;j++){
	  plays[move++] = 2;
	}
	for(j=0;j<n-1;j++){
	  plays[move++] = 0;
	}
      }
            
      board[0][0] = 'O';
      int p,q,x = 0,y = 0;
      char dmp;
      int ap = 0;

      for(i=0;i<move;i++){

	for(p=0;p<n;p++){
	  for(q=0;q<m;q++){
	    board[p][q] = 'O';
	  }
	}
	if(plays[i] == 2){
	  //	  board[x][y] = 'O';
	  x = (x-1+n)%n;
	  if(board[x][y] == '*'){
	    //	    printf("ERROR: 2\n");
	    assert(n < 0);
	    //	    break;
	  }
	  board[x][y] = '*';
	  if(pos[ap][0] == y && pos[ap][1] == x){
	    ap++;
	  }
	}
	else if(plays[i] == 3){
	  //	  board[x][y] = 'O';
	  x = (x+1)%n;
	  if(board[x][y] == '*'){
	    //	    printf("ERROR 3\n");
	    assert(n < 0);
	    //	    break;
	  }
	  board[x][y] = '*';
	  if(pos[ap][0] == y && pos[ap][1] == x)
	    ap++;
	}
	else if(plays[i] == 0){
	  //	  board[x][y] = 'O';
	  y = (y+m-1)%m;
	  if(board[x][y] == '*'){
	    //	    printf("ERROR 0\n");
	    assert(n < 0);
	    //	    break;
	  }
	  board[x][y] = '*';
	  if(pos[ap][0] == y && pos[ap][1] == x)
	    ap++;
	}
	else{
	  //	  board[x][y] = 'O';
	  y = (y+1)%m;
	  if(board[x][y] == '*'){
	    //	    printf("ERROR 1\n");
	    assert(n < 0);
	    //	    break;
	  }
	  board[x][y] = '*';
	  if(pos[ap][0] == y && pos[ap][1] == x)
	    ap++;
	}
	/*
	for(p=n-1;p>=0;p--){
	  for(q=0;q<m;q++)
	    printf("%c ",board[p][q]);
	  printf("\n");
	}
	*/
	if(ap == apples)
	  break;	
      }
      //      printf("ap = %d\n",ap);
      printf("%d\n",i+1);      
      for(j=0;j<=i;j++){
	printf("%d ",plays[j]);
      }
      printf("\n");      
    }
    else{
      for(i=0;i<=apples;i++){

	for(j=0;j<n-1;j++){
	  plays[move++] = 3;
	}

	in_rep = (m-2)/2;
	for(k = 0; k < in_rep; k++){
	  plays[move++] = 1;
	  for(j=0;j<n-2;j++){
	    plays[move++] = 2;
	  }
	  plays[move++] = 1;
	  for(j=0;j<n-2;j++){
	    plays[move++] = 3;
	  }
	}
	plays[move++] = 1;
	for(j=0;j<n-1;j++){
	  plays[move++] = 2;
	}
	for(j=0;j<m-1;j++){
	  plays[move++] = 0;
	}
      }
      /*
      for(i=0;i<move-1;i++){
	printf("%d ",plays[i]);
      }
      printf("%d\n",plays[move-1]);
      */
      //      printf("\n");
      
      board[0][0] = 'O';
      int p,q,x = 0,y = 0;
      char dmp;
      int ap = 0;

      for(i=0;i<move;i++){

	for(p=0;p<n;p++){
	  for(q=0;q<m;q++){
	    board[p][q] = 'O';
	  }
	}

	if(plays[i] == 2){
	  //	  board[x][y] = 'O';
	  x = (x-1+n)%n;
	  if(board[x][y] == '*'){
	    //	    printf("ERROR 3\n");
	    assert(n < 0);
	    //	    break;
	  }
	  board[x][y] = '*';
	  if(pos[ap][0] == y && pos[ap][1] == x)
	    ap++;
	}
	else if(plays[i] == 3){
	  //	  board[x][y] = 'O';
	  x = (x+1)%n;
	  if(board[x][y] == '*'){
	    //	    printf("ERROR 3\n");
	    assert(n < 0);
	    //	    break;
	  }
	  board[x][y] = '*';
	  if(pos[ap][0] == y && pos[ap][1] == x)
	    ap++;
	}
	else if(plays[i] == 0){
	  //	  board[x][y] = 'O';
	  y = (y+m-1)%m;
	  if(board[x][y] == '*'){
	    //	    printf("ERROR 3\n");
	    assert(n < 0);
	    //	    break;
	  }
	  board[x][y] = '*';
	  if(pos[ap][0] == y && pos[ap][1] == x)
	    ap++;
	}
	else{
	  //	  board[x][y] = 'O';
	  y = (y+1)%m;
	  if(board[x][y] == '*'){
	    //	    printf("ERROR 3\n");
	    assert(n < 0);
	    //	    break;
	  }
	  board[x][y] = '*';
	  if(pos[ap][0] == y && pos[ap][1] == x)
	    ap++;
	}
	if(ap == apples)
	  break;
	/*
	for(p=n-1;p>=0;p--){
	  for(q=0;q<m;q++)
	    printf("%c ",board[p][q]);
	  printf("\n");
	}
	*/
      }
      printf("%d\n",i+1);      
      for(j=0;j<=i;j++){
	printf("%d ",plays[j]);
      }
      printf("\n");      
    }

  }
  return 0;
}
/*
4 5
0 1
0 1
0 1
0 1
0 1
0 1
0 1
0 1
0 1
0 1
0 1
0 1
0 1
0 1
0 1
0 1
0 1
0 1
0 1

4 5
1 0
2 0
3 0
4 0
4 1
3 1
2 1
1 1
1 2
2 2
3 2
4 2
4 3
3 3
2 3
1 3
0 3
0 2
0 1

5 4
0 1
0 2
0 3
0 4
1 4
1 3
1 2
1 1
2 1
2 2
2 3
2 4
3 4
3 3
3 2
3 1
3 0
2 0
1 0

2 5
0 1
1 1
2 1
3 1
4 1
4 0
3 0
2 0
1 0

2 5
1 0
2 0
3 0
4 0
4 1
3 1
2 1
1 1
0 1

5 2
1 0
2 0
3 0
4 0
4 1
3 1
2 1
1 1
0 1
*/
