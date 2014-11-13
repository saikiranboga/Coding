#include <iostream>
#include <iomanip>
#include <vector>
#include <map>
#include <string>
#include <algorithm>
#include <fstream>
#include <ctime>
#include <cstring>
#include <cmath>
#include <cstdio>
#include <cassert>
#include <fstream>
using namespace std;
#define ll long long
#define fore(i,l,r) for(int i=(l);i<(r);++i)
#define forn(i,n) fore(i,0,n)
#define fori(i,l,r) fore(i,l,(r)+1)
#define ford(i,up,bot) for(int i=(up);i>(bot);--i)
#define fordi(i,up,bot) ford(i,up,bot-1)
#define pb push_back
using namespace std;
ofstream fout ("LMATRIX2.out");
typedef struct info
{int x1, x2, y1, y2, k;}info;

int main(){
    ios_base::sync_with_stdio(false);
    int n,m;
    cin>>n>>m;
    int P[n+1][m+1], A[n+1][m+1];
    vector<info> ans;

    fori(i, 1, n)fori(j, 1, m) cin >> P[i][j];

    int mx=0,k_all=0;
    fori(i, 1, n)
        fori(j, 1, m){
            cin>>A[i][j];
            if(A[i][j]==0)
                mx++;
        }
        fori(k,0,3000){
            int cnt = 0;
            fori(i,1,n)
                fori(j,1,m)
                    if((A[i][j]+k)%P[i][j]==0)
                        cnt++;
            if(cnt>mx)
                k_all = k; mx = cnt;
        }
        fori(i, 1, n) fori(j, 1, m) A[i][j] = (A[i][j]+k_all)%P[i][j];
        info all; all.x1=1,all.y1=1,all.x2=n,all.y2=m,all.k=k_all; ans.pb(all);
    //e

    //12x12
    for(int i=1;i<=n-11;i+=12){
        for(int j=1;j<=m-11;j+=12){
            int zeros = 0;
            int new_zeros, new_k;
            int mx = 0;
            fore(r, i, i+12)
                fore(c, j, j+12)
                    if(A[r][c]%P[r][c]==0)
                        zeros++;
            if(zeros < 80){
                mx = 0;
                forn(k, 610){
                    new_zeros = 0;
                    fore(r, i, i+12)
                        fore(c, j, j+12)
                            if( (A[r][c]+k)%P[r][c]==0)
                                new_zeros++;
                    if(new_zeros > mx){
                        mx = new_zeros;
                        new_k = k;
                    }
                }
            }

            if(mx>zeros+25){
                info add;
                add.x1 = i;
                add.x2 = i+11;
                add.y1 = j;
                add.y2 = j+11;
                add.k = new_k;
                ans.pb(add);
                fore(r, i, i+12)
                    fore(c, j, j+12)
                        A[r][c] = (A[r][c]+new_k)%P[r][c];
            }

        }

    }
    // end

    //10x10
    for(int i=1;i<=n-9;i+=10){
        for(int j=1;j<=m-9;j+=10){
            int zeros = 0;
            int new_zeros, new_k;
            int mx = 0;
            fore(r, i, i+10)
                fore(c, j, j+10)
                    if(A[r][c]%P[r][c]==0)
                        zeros++;
            if(zeros < 70){
                mx = 0;
                forn(k, 110){
                    new_zeros = 0;
                    fore(r, i, i+10)
                        fore(c, j, j+10)
                            if( (A[r][c]+k)%P[r][c]==0)
                                new_zeros++;
                    if(new_zeros > mx){
                        mx = new_zeros;
                        new_k = k;
                    }
                }
            }

            if(mx>zeros+20){
                info add;
                add.x1 = i;
                add.x2 = i+9;
                add.y1 = j;
                add.y2 = j+9;
                add.k = new_k;
                ans.pb(add);
                fore(r, i, i+10)
                    fore(c, j, j+10)
                        A[r][c] = (A[r][c]+new_k)%P[r][c];
            }

        }

    }
    // end

    //8x8
    for(int i=1;i<=n-7;i+=8){
        for(int j=1;j<=m-7;j+=8){
            int zeros = 0;
            int new_zeros, new_k;
            int mx = 0;
            fore(r, i, i+8)
                fore(c, j, j+8)
                    if(A[r][c]%P[r][c]==0)
                        zeros++;
            if(zeros < 20){
                mx = 0;
                forn(k, 610){
                    new_zeros = 0;
                    fore(r, i, i+8)
                        fore(c, j, j+8)
                            if( (A[r][c]+k)%P[r][c]==0)
                                new_zeros++;
                    if(new_zeros > mx){
                        mx = new_zeros;
                        new_k = k;
                    }
                }
            }

            if(mx>40){
                info add;
                add.x1 = i;
                add.x2 = i+7;
                add.y1 = j;
                add.y2 = j+7;
                add.k = new_k;
                ans.pb(add);
                fore(r, i, i+8)
                    fore(c, j, j+8)
                        A[r][c] = (A[r][c]+new_k)%P[r][c];
            }

        }

    }
    // end


    //10x6
    for(int i=1;i<=n-9;i+=10){
        for(int j=1;j<=m-5;j+=6){
            int zeros = 0;
            int new_zeros, new_k;
            int mx = 0;
            fore(r, i, i+10)
                fore(c, j, j+6)
                    if(A[r][c]%P[r][c]==0)
                        zeros++;
            if(zeros < 20){
                mx = 0;
                forn(k, 610){
                    new_zeros = 0;
                    fore(r, i, i+10)
                        fore(c, j, j+6)
                            if( (A[r][c]+k)%P[r][c]==0)
                                new_zeros++;
                    if(new_zeros > mx){
                        mx = new_zeros;
                        new_k = k;
                    }
                }
            }

            if(mx>zeros+20){
                info add;
                add.x1 = i;
                add.x2 = i+9;
                add.y1 = j;
                add.y2 = j+5;
                add.k = new_k;
                ans.pb(add);
                fore(r, i, i+10)
                    fore(c, j, j+6)
                        A[r][c] = (A[r][c]+new_k)%P[r][c];
            }

        }

    }
    // end

    //6x10
    for(int i=1;i<=n-5;i+=6){
        for(int j=1;j<=m-9;j+=10){
            int zeros = 0;
            int new_zeros, new_k;
            int mx = 0;
            fore(r, i, i+6)
                fore(c, j, j+10)
                    if(A[r][c]%P[r][c]==0)
                        zeros++;
            if(zeros < 20){
                mx = 0;
                forn(k, 110){
                    new_zeros = 0;
                    fore(r, i, i+6)
                        fore(c, j, j+10)
                            if( (A[r][c]+k)%P[r][c]==0)
                                new_zeros++;
                    if(new_zeros > mx){
                        mx = new_zeros;
                        new_k = k;
                    }
                }
            }

            if(mx>zeros+20){
                info add;
                add.x1 = i;
                add.x2 = i+5;
                add.y1 = j;
                add.y2 = j+9;
                add.k = new_k;
                ans.pb(add);
                fore(r, i, i+6)
                    fore(c, j, j+10)
                        A[r][c] = (A[r][c]+new_k)%P[r][c];
            }

        }

    }
    // end
    //7x7
    for(int i=1;i<=n-6;i+=7){
        for(int j=1;j<=m-6;j+=7){
            int zeros = 0;
            int new_zeros, new_k;
            int mx = 0;
            fore(r, i, i+7)
                fore(c, j, j+7)
                    if(A[r][c]%P[r][c]==0)
                        zeros++;
            if(zeros < 20){
                mx = 0;
                forn(k, 610){
                    new_zeros = 0;
                    fore(r, i, i+7)
                        fore(c, j, j+7)
                            if( (A[r][c]+k)%P[r][c]==0)
                                new_zeros++;
                    if(new_zeros > mx){
                        mx = new_zeros;
                        new_k = k;
                    }
                }
            }

            if(mx>zeros+15){
                info add;
                add.x1 = i;
                add.x2 = i+6;
                add.y1 = j;
                add.y2 = j+6;
                add.k = new_k;
                ans.pb(add);
                fore(r, i, i+7)
                    fore(c, j, j+7)
                        A[r][c] = (A[r][c]+new_k)%P[r][c];
            }

        }

    }
    // end

    //10x4
    for(int i=1;i<=n-9;i+=10){
        for(int j=1;j<=m-3;j+=4){
            int zeros = 0;
            int new_zeros, new_k;
            int mx = 0;
            fore(r, i, i+10)
                fore(c, j, j+4)
                    if(A[r][c]%P[r][c]==0)
                        zeros++;
            if(zeros < 20){
                mx = 0;
                forn(k, 610){
                    new_zeros = 0;
                    fore(r, i, i+10)
                        fore(c, j, j+4)
                            if( (A[r][c]+k)%P[r][c]==0)
                                new_zeros++;
                    if(new_zeros > mx){
                        mx = new_zeros;
                        new_k = k;
                    }
                }
            }

            if(mx>zeros+10){
                info add;
                add.x1 = i;
                add.x2 = i+9;
                add.y1 = j;
                add.y2 = j+3;
                add.k = new_k;
                ans.pb(add);
                fore(r, i, i+10)
                    fore(c, j, j+4)
                        A[r][c] = (A[r][c]+new_k)%P[r][c];
            }

        }

    }
    // end

    //4x10
    for(int i=1;i<=n-3;i+=4){
        for(int j=1;j<=m-9;j+=10){
            int zeros = 0;
            int new_zeros, new_k;
            int mx = 0;
            fore(r, i, i+4)
                fore(c, j, j+10)
                    if(A[r][c]%P[r][c]==0)
                        zeros++;
            if(zeros < 20){
                mx = 0;
                forn(k, 610){
                    new_zeros = 0;
                    fore(r, i, i+4)
                        fore(c, j, j+10)
                            if( (A[r][c]+k)%P[r][c]==0)
                                new_zeros++;
                    if(new_zeros > mx){
                        mx = new_zeros;
                        new_k = k;
                    }
                }
            }

            if(mx>zeros+10){
                info add;
                add.x1 = i;
                add.x2 = i+3;
                add.y1 = j;
                add.y2 = j+9;
                add.k = new_k;
                ans.pb(add);
                fore(r, i, i+4)
                    fore(c, j, j+10)
                        A[r][c] = (A[r][c]+new_k)%P[r][c];
            }

        }

    }
    // end


    //6x6
    for(int i=1;i<=n-5;i+=6){
        for(int j=1;j<=m-5;j+=6){
            int zeros = 0;
            int new_zeros, new_k;
            int mx = 0;
            fore(r, i, i+6)
                fore(c, j, j+6)
                    if(A[r][c]%P[r][c]==0)
                        zeros++;
            if(zeros < 15){
                mx = 0;
                forn(k, 610){
                    new_zeros = 0;
                    fore(r, i, i+6)
                        fore(c, j, j+6)
                            if( (A[r][c]+k)%P[r][c]==0)
                                new_zeros++;
                    if(new_zeros > mx){
                        mx = new_zeros;
                        new_k = k;
                    }
                }
            }

            if(mx>zeros+10){
                info add;
                add.x1 = i;
                add.x2 = i+5;
                add.y1 = j;
                add.y2 = j+5;
                add.k = new_k;
                ans.pb(add);
                fore(r, i, i+6)
                    fore(c, j, j+6)
                        A[r][c] = (A[r][c]+new_k)%P[r][c];
            }

        }

    }
    // end

    //8x4
    for(int i=1;i<=n-7;i+=8){
        for(int j=1;j<=m-3;j+=4){
            int new_zeros,new_k,mx=0,zeros=0;
            fore(r,i,i+8)fore(c,j,j+4)if(A[r][c]%P[r][c]==0)zeros++;
            if(zeros<18){
                mx=0;
                forn(k,610){
                    new_zeros=0;
                    fore(r,i,i+8)fore(c,j,j+4)if((A[r][c]+k)%P[r][c]==0)new_zeros++;
                    if(new_zeros>mx){
                        mx=new_zeros;new_k=k;
                    }
                }
            }
            if(mx>zeros+8){
                info add;add.x1=i;add.x2=i+7;add.y1=j;add.y2=j+3;add.k=new_k;ans.pb(add);
                fore(r,i,i+8)fore(c,j,j+4)A[r][c]=(A[r][c]+new_k)%P[r][c];
            }
        }
    }
    // end

    //4x8
    for(int i=1;i<=n-3;i+=4){
        for(int j=1;j<=m-7;j+=8){
            int new_zeros,new_k,mx=0,zeros=0;
            fore(r, i, i+4)
                fore(c, j, j+8)
                    if(A[r][c]%P[r][c]==0)
                        zeros++;
            if(zeros < 18){
                mx = 0;
                forn(k, 610){
                    new_zeros = 0;
                    fore(r, i, i+4)
                        fore(c, j, j+8)
                            if( (A[r][c]+k)%P[r][c]==0)
                                new_zeros++;
                    if(new_zeros > mx){
                        mx = new_zeros;
                        new_k = k;
                    }
                }
            }

            if(mx>zeros+8){
                info add;
                add.x1 = i;
                add.x2 = i+3;
                add.y1 = j;
                add.y2 = j+7;
                add.k = new_k;
                ans.pb(add);
                fore(r, i, i+4)
                    fore(c, j, j+8)
                        A[r][c] = (A[r][c]+new_k)%P[r][c];
            }

        }

    }
    //12x2
    for(int i=1;i<=n-11;i+=12){
        for(int j=1;j<=m-1;j+=2){
            int new_zeros,new_k,mx=0,zeros=0;
            fore(r,i,i+12)fore(c,j,j+2)if(A[r][c]%P[r][c]==0)zeros++;
            if(zeros<15){
                mx=0;
                forn(k,610){
                    new_zeros=0;
                    fore(r,i,i+12)fore(c,j,j+2)if((A[r][c]+k)%P[r][c]==0)new_zeros++;
                    if(new_zeros>mx){
                        mx = new_zeros;new_k = k;
                    }
                }
            }
            if(mx>zeros+6){
                info add;add.x1=i;add.x2=i+11;add.y1=j;add.y2=j+1;add.k=new_k;ans.pb(add);
                fore(r,i,i+12)fore(c,j,j+2)A[r][c]=(A[r][c]+new_k)%P[r][c];
            }
        }
    }
    // end
    //2x12
    for(int i=1;i<=n-1;i+=2){
        for(int j=1;j<=m-11;j+=12){
            int new_zeros,new_k,mx=0,zeros=0;
            fore(r,i,i+2)fore(c,j,j+12)if(A[r][c]%P[r][c]==0)zeros++;
            if(zeros<15){
                mx=0;
                forn(k,610){
                    new_zeros=0;
                    fore(r,i,i+2)fore(c,j,j+12)if((A[r][c]+k)%P[r][c]==0)new_zeros++;
                    if(new_zeros>mx){
                        mx=new_zeros;new_k=k;
                    }
                }
            }
            if(mx>zeros+6){
                info add;add.x1=i;add.x2=i+1;add.y1=j;add.y2=j+11;add.k=new_k;ans.pb(add);
                fore(r,i,i+2)fore(c, j, j+12)A[r][c]=(A[r][c]+new_k)%P[r][c];
            }
        }
    }
    // end
    for(int i=1;i<=n-4;i+=5){
        for(int j=1;j<=m-4;j+=5){
            int zeros = 0;
            int new_zeros, new_k;
            int mx = 0;
            fore(r, i, i+5)
                fore(c, j, j+5)
                    if(A[r][c]%P[r][c]==0)
                        zeros++;
            if(zeros < 10){
                mx = 0;
                forn(k, 610){
                    new_zeros = 0;
                    fore(r, i, i+5)
                        fore(c, j, j+5)
                            if( (A[r][c]+k)%P[r][c]==0)
                                new_zeros++;
                    if(new_zeros > mx){
                        mx = new_zeros;
                        new_k = k;
                    }
                }
            }

            if(mx>zeros+6){
                info add;
                add.x1 = i;
                add.x2 = i+4;
                add.y1 = j;
                add.y2 = j+4;
                add.k = new_k;
                ans.pb(add);
                fore(r, i, i+5)
                    fore(c, j, j+5)
                        A[r][c] = (A[r][c]+new_k)%P[r][c];
            }

        }

    }
    for(int i=1;i<=n-9;i+=10){
        for(int j=1;j<=m-1;j+=2){
            int zeros = 0;
            int new_zeros, new_k;
            int mx = 0;
            fore(r, i, i+10)
                fore(c, j, j+2)
                    if(A[r][c]%P[r][c]==0)
                        zeros++;
            if(zeros < 12){
                mx = 0;
                forn(k, 610){
                    new_zeros = 0;
                    fore(r, i, i+10)
                        fore(c, j, j+2)
                            if( (A[r][c]+k)%P[r][c]==0)
                                new_zeros++;
                    if(new_zeros > mx){
                        mx = new_zeros;
                        new_k = k;
                    }
                }
            }

            if(mx>zeros+8){
                info add;
                add.x1 = i;
                add.x2 = i+9;
                add.y1 = j;
                add.y2 = j+1;
                add.k = new_k;
                ans.pb(add);
                fore(r, i, i+10)
                    fore(c, j, j+2)
                        A[r][c] = (A[r][c]+new_k)%P[r][c];
            }

        }

    }
    for(int i=1;i<=n-1;i+=2){
        for(int j=1;j<=m-9;j+=10){
            int zeros = 0;
            int new_zeros, new_k;
            int mx = 0;
            fore(r, i, i+2)
                fore(c, j, j+10)
                    if(A[r][c]%P[r][c]==0)
                        zeros++;
            if(zeros < 12){
                mx = 0;
                forn(k, 610){
                    new_zeros = 0;
                    fore(r, i, i+2)
                        fore(c, j, j+10)
                            if( (A[r][c]+k)%P[r][c]==0)
                                new_zeros++;
                    if(new_zeros > mx){
                        mx = new_zeros;
                        new_k = k;
                    }
                }
            }

            if(mx>zeros+8){
                info add;
                add.x1 = i;
                add.x2 = i+1;
                add.y1 = j;
                add.y2 = j+9;
                add.k = new_k;
                ans.pb(add);
                fore(r, i, i+2)
                    fore(c, j, j+10)
                        A[r][c] = (A[r][c]+new_k)%P[r][c];
            }

        }

    }
    for(int i=1;i<=n-6;i+=7){
        for(int j=1;j<=m-2;j+=3){
            int zeros = 0;
            int new_zeros, new_k;
            int mx = 0;
            fore(r, i, i+7)
                fore(c, j, j+3)
                    if(A[r][c]%P[r][c]==0)
                        zeros++;
            if(zeros < 15){
                mx = 0;
                forn(k, 610){
                    new_zeros = 0;
                    fore(r, i, i+7)
                        fore(c, j, j+3)
                            if( (A[r][c]+k)%P[r][c]==0)
                                new_zeros++;
                    if(new_zeros > mx){
                        mx = new_zeros;
                        new_k = k;
                    }
                }
            }

            if(mx>zeros+8){
                info add;
                add.x1 = i;
                add.x2 = i+6;
                add.y1 = j;
                add.y2 = j+2;
                add.k = new_k;
                ans.pb(add);
                fore(r, i, i+7)
                    fore(c, j, j+3)
                        A[r][c] = (A[r][c]+new_k)%P[r][c];
            }

        }

    }
    for(int i=1;i<=n-2;i+=3){
        for(int j=1;j<=m-6;j+=7){
            int zeros = 0;
            int new_zeros, new_k;
            int mx = 0;
            fore(r, i, i+3)
                fore(c, j, j+7)
                    if(A[r][c]%P[r][c]==0)
                        zeros++;
            if(zeros < 15){
                mx = 0;
                forn(k, 610){
                    new_zeros = 0;
                    fore(r, i, i+3)
                        fore(c, j, j+7)
                            if( (A[r][c]+k)%P[r][c]==0)
                                new_zeros++;
                    if(new_zeros > mx){
                        mx = new_zeros;
                        new_k = k;
                    }
                }
            }

            if(mx>zeros+8){
                info add;
                add.x1 = i;
                add.x2 = i+2;
                add.y1 = j;
                add.y2 = j+6;
                add.k = new_k;
                ans.pb(add);
                fore(r, i, i+3)
                    fore(c, j, j+7)
                        A[r][c] = (A[r][c]+new_k)%P[r][c];
            }

        }

    }
    for(int i=1;i<=n-7;i+=8){
        for(int j=1;j<=m-1;j+=2){
            int zeros = 0;
            int new_zeros, new_k;
            int mx = 0;
            fore(r, i, i+8)
                fore(c, j, j+2)
                    if(A[r][c]%P[r][c]==0)
                        zeros++;
            if(zeros < 10){
                mx = 0;
                forn(k, 610){
                    new_zeros = 0;
                    fore(r, i, i+8)
                        fore(c, j, j+2)
                            if( (A[r][c]+k)%P[r][c]==0)
                                new_zeros++;
                    if(new_zeros > mx){
                        mx = new_zeros;
                        new_k = k;
                    }
                }
            }

            if(mx>zeros+6){
                info add;
                add.x1 = i;
                add.x2 = i+7;
                add.y1 = j;
                add.y2 = j+1;
                add.k = new_k;
                ans.pb(add);
                fore(r, i, i+8)
                    fore(c, j, j+2)
                        A[r][c] = (A[r][c]+new_k)%P[r][c];
            }

        }

    }
    for(int i=1;i<=n-1;i+=2){
        for(int j=1;j<=m-7;j+=8){
            int zeros = 0;
            int new_zeros, new_k;
            int mx = 0;
            fore(r, i, i+2)
                fore(c, j, j+8)
                    if(A[r][c]%P[r][c]==0)
                        zeros++;
            if(zeros < 10){
                mx = 0;
                forn(k, 810){
                    new_zeros = 0;
                    fore(r, i, i+2)
                        fore(c, j, j+8)
                            if( (A[r][c]+k)%P[r][c]==0)
                                new_zeros++;
                    if(new_zeros > mx){
                        mx = new_zeros;
                        new_k = k;
                    }
                }
            }

            if(mx>zeros+6){
                info add;
                add.x1 = i;
                add.x2 = i+1;
                add.y1 = j;
                add.y2 = j+7;
                add.k = new_k;
                ans.pb(add);
                fore(r, i, i+2)
                    fore(c, j, j+8)
                        A[r][c] = (A[r][c]+new_k)%P[r][c];
            }

        }

    }
    for(int i=1;i<=n-4;i+=5){
        for(int j=1;j<=m-2;j+=3){
            int zeros = 0;
            int new_zeros, new_k;
            int mx = 0;
            fore(r, i, i+5)
                fore(c, j, j+3)
                    if(A[r][c]%P[r][c]==0)
                        zeros++;
            if(zeros < 10){
                mx = 0;
                forn(k, 810){
                    new_zeros = 0;
                    fore(r, i, i+5)
                        fore(c, j, j+3)
                            if( (A[r][c]+k)%P[r][c]==0)
                                new_zeros++;
                    if(new_zeros > mx){
                        mx = new_zeros;
                        new_k = k;
                    }
                }
            }

            if(mx>zeros+3){
                info add;
                add.x1 = i;
                add.x2 = i+4;
                add.y1 = j;
                add.y2 = j+2;
                add.k = new_k;
                ans.pb(add);
                fore(r, i, i+5)
                    fore(c, j, j+3)
                        A[r][c] = (A[r][c]+new_k)%P[r][c];
            }

        }

    }
    for(int i=1;i<=n-2;i+=3){
        for(int j=1;j<=m-4;j+=5){
            int zeros = 0;
            int new_zeros, new_k;
            int mx = 0;
            fore(r, i, i+3)
                fore(c, j, j+5)
                    if(A[r][c]%P[r][c]==0)
                        zeros++;
            if(zeros < 10){
                mx = 0;
                forn(k, 810){
                    new_zeros = 0;
                    fore(r, i, i+3)
                        fore(c, j, j+5)
                            if( (A[r][c]+k)%P[r][c]==0)
                                new_zeros++;
                    if(new_zeros > mx){
                        mx = new_zeros;
                        new_k = k;
                    }
                }
            }

            if(mx>zeros+3){
                info add;
                add.x1 = i;
                add.x2 = i+2;
                add.y1 = j;
                add.y2 = j+4;
                add.k = new_k;
                ans.pb(add);
                fore(r, i, i+3)
                    fore(c, j, j+5)
                        A[r][c] = (A[r][c]+new_k)%P[r][c];
            }

        }

    }
    for(int i=1;i<=n-3;i+=4){
        for(int j=1;j<=m-3;j+=4){
            int zeros = 0;
            int new_zeros, new_k;
            int mx = 0;
            fore(r, i, i+4)
                fore(c, j, j+4)
                    if(A[r][c]%P[r][c]==0)
                        zeros++;
            if(zeros < 5){
                mx = 0;
                forn(k, 810){
                    new_zeros = 0;
                    fore(r, i, i+4)
                        fore(c, j, j+4)
                            if( (A[r][c]+k)%P[r][c]==0)
                                new_zeros++;
                    if(new_zeros > mx){
                        mx = new_zeros;
                        new_k = k;
                    }
                }
            }

            if(mx>zeros+5){
                info add;
                add.x1 = i;
                add.x2 = i+3;
                add.y1 = j;
                add.y2 = j+3;
                add.k = new_k;
                ans.pb(add);
                fore(r, i, i+4)
                    fore(c, j, j+4)
                        A[r][c] = (A[r][c]+new_k)%P[r][c];
            }
        }
    }
    //25x1
    for(int i=1;i<=n-24;i+=25){
        for(int j=1;j<=m;j+=1){
            int new_zeros,new_k,mx=0,zeros=0;
            fore(r,i,i+25)fore(c,j,j+1)if(A[r][c]%P[r][c]==0)zeros++;
            if(zeros<15){
                mx=0;
                forn(k,810){
                    new_zeros=0;
                    fore(r,i,i+25)fore(c,j,j+1)if((A[r][c]+k)%P[r][c]==0)new_zeros++;
                    if(new_zeros>mx){
                        mx = new_zeros;new_k = k;
                    }
                }
            }
            if(mx>zeros+10){
                info add;add.x1=i;add.x2=i+24;add.y1=j;add.y2=j;add.k=new_k;ans.pb(add);
                fore(r,i,i+25)fore(c,j,j+1)A[r][c]=(A[r][c]+new_k)%P[r][c];
            }
        }
    }
    //1x25
    for(int i=1;i<=n;i+=1){
        for(int j=1;j<=m-14;j+=15){
            int new_zeros,new_k,mx=0,zeros=0;
            fore(r,i,i+1)fore(c,j,j+15)if(A[r][c]%P[r][c]==0)zeros++;
            if(zeros<15){
                mx=0;
                forn(k,810){
                    new_zeros=0;
                    fore(r,i,i+1)fore(c,j,j+15)if((A[r][c]+k)%P[r][c]==0)new_zeros++;
                    if(new_zeros>mx){
                        mx=new_zeros;new_k=k;
                    }
                }
            }
            if(mx>zeros+10){
                info add;add.x1=i;add.x2=i;add.y1=j;add.y2=j+14;add.k=new_k;ans.pb(add);
                fore(r,i,i+1)fore(c, j, j+15)A[r][c]=(A[r][c]+new_k)%P[r][c];
            }
        }
    }
    //12x1
    for(int i=1;i<=n-11;i+=12){
        for(int j=1;j<=m;j+=1){
            int new_zeros,new_k,mx=0,zeros=0;
            fore(r,i,i+12)fore(c,j,j+1)if(A[r][c]%P[r][c]==0)zeros++;
            if(zeros<8){
                mx=0;
                forn(k,810){
                    new_zeros=0;
                    fore(r,i,i+12)fore(c,j,j+1)if((A[r][c]+k)%P[r][c]==0)new_zeros++;
                    if(new_zeros>mx){
                        mx = new_zeros;new_k = k;
                    }
                }
            }
            if(mx>zeros+4){
                info add;add.x1=i;add.x2=i+11;add.y1=j;add.y2=j;add.k=new_k;ans.pb(add);
                fore(r,i,i+12)fore(c,j,j+1)A[r][c]=(A[r][c]+new_k)%P[r][c];
            }
        }
    }
    // end
    //1x12
    for(int i=1;i<=n;i+=1){
        for(int j=1;j<=m-11;j+=12){
            int new_zeros,new_k,mx=0,zeros=0;
            fore(r,i,i+1)fore(c,j,j+12)if(A[r][c]%P[r][c]==0)zeros++;
            if(zeros<8){
                mx=0;
                forn(k,810){
                    new_zeros=0;
                    fore(r,i,i+1)fore(c,j,j+12)if((A[r][c]+k)%P[r][c]==0)new_zeros++;
                    if(new_zeros>mx){
                        mx=new_zeros;new_k=k;
                    }
                }
            }
            if(mx>zeros+4){
                info add;add.x1=i;add.x2=i;add.y1=j;add.y2=j+11;add.k=new_k;ans.pb(add);
                fore(r,i,i+1)fore(c, j, j+12)A[r][c]=(A[r][c]+new_k)%P[r][c];
            }
        }
    }
    // end
    for(int i=1;i<=n-5;i+=6){
        for(int j=1;j<=m-1;j+=2){
            int new_zeros,new_k,mx=0,zeros=0;
            fore(r,i,i+6)fore(c,j,j+2)if(A[r][c]%P[r][c]==0)zeros++;
            if(zeros < 8){
                mx = 0;
                forn(k, 810){
                    new_zeros = 0;
                    fore(r, i, i+6)
                        fore(c, j, j+2)
                            if( (A[r][c]+k)%P[r][c]==0)
                                new_zeros++;
                    if(new_zeros > mx){
                        mx = new_zeros;
                        new_k = k;
                    }
                }
            }

            if(mx>zeros+6){
                info add;
                add.x1 = i;
                add.x2 = i+5;
                add.y1 = j;
                add.y2 = j+1;
                add.k = new_k;
                ans.pb(add);
                fore(r, i, i+6)
                    fore(c, j, j+2)
                        A[r][c] = (A[r][c]+new_k)%P[r][c];
            }

        }

    }
    for(int i=1;i<=n-1;i+=2){
        for(int j=1;j<=m-5;j+=6){
            int new_zeros,new_k,mx=0,zeros=0;
            fore(r, i, i+2)
                fore(c, j, j+6)
                    if(A[r][c]%P[r][c]==0)
                        zeros++;
            if(zeros < 6){
                mx = 0;
                forn(k, 610){
                    new_zeros = 0;
                    fore(r, i, i+2)
                        fore(c, j, j+6)
                            if( (A[r][c]+k)%P[r][c]==0)
                                new_zeros++;
                    if(new_zeros > mx){
                        mx = new_zeros;
                        new_k = k;
                    }
                }
            }

            if(mx>zeros+5){
                info add;
                add.x1 = i;
                add.x2 = i+1;
                add.y1 = j;
                add.y2 = j+5;
                add.k = new_k;
                ans.pb(add);
                fore(r, i, i+2)
                    fore(c, j, j+6)
                        A[r][c] = (A[r][c]+new_k)%P[r][c];
            }

        }

    }
    for(int i=1;i<=n-3;i+=4){
        for(int j=1;j<=m-1;j+=2){
            int new_zeros,new_k,mx=0,zeros=0;
            fore(r, i, i+4)
                fore(c, j, j+2)
                    if(A[r][c]%P[r][c]==0)
                        zeros++;
            if(zeros < 5){
                mx = 0;
                forn(k, 610){
                    new_zeros = 0;
                    fore(r, i, i+4)
                        fore(c, j, j+2)
                            if( (A[r][c]+k)%P[r][c]==0)
                                new_zeros++;
                    if(new_zeros > mx){
                        mx = new_zeros;
                        new_k = k;
                    }
                }
            }

            if(mx>zeros+2){
                info add;
                add.x1 = i;
                add.x2 = i+3;
                add.y1 = j;
                add.y2 = j+1;
                add.k = new_k;
                ans.pb(add);
                fore(r, i, i+4)
                    fore(c, j, j+2)
                        A[r][c] = (A[r][c]+new_k)%P[r][c];
            }

        }

    }
    for(int i=1;i<=n-1;i+=2){
        for(int j=1;j<=m-3;j+=4){
            int new_zeros,new_k,mx=0,zeros=0;
            fore(r, i, i+2)
                fore(c, j, j+4)
                    if(A[r][c]%P[r][c]==0)
                        zeros++;
            if(zeros < 5){
                mx = 0;
                forn(k, 610){
                    new_zeros = 0;
                    fore(r, i, i+2)
                        fore(c, j, j+4)
                            if( (A[r][c]+k)%P[r][c]==0)
                                new_zeros++;
                    if(new_zeros > mx){
                        mx = new_zeros;
                        new_k = k;
                    }
                }
            }

            if(mx>zeros+2){
                info add;
                add.x1 = i;
                add.x2 = i+1;
                add.y1 = j;
                add.y2 = j+3;
                add.k = new_k;
                ans.pb(add);
                fore(r, i, i+2)
                    fore(c, j, j+4)
                        A[r][c] = (A[r][c]+new_k)%P[r][c];
            }

        }

    }
    for(int i=1;i<=n-2;i+=3){
        for(int j=1;j<=m-2;j+=3){
            int new_zeros,new_k,mx=0,zeros=0;
            fore(r, i, i+3)
                fore(c, j, j+3)
                    if(A[r][c]%P[r][c]==0)
                        zeros++;
            if(zeros < 3){
                mx = 0;
                forn(k, 610){
                    new_zeros = 0;
                    fore(r, i, i+3)
                        fore(c, j, j+3)
                            if( (A[r][c]+k)%P[r][c]==0)
                                new_zeros++;
                    if(new_zeros > mx){
                        mx = new_zeros;
                        new_k = k;
                    }
                }
            }

            if(mx>zeros+5){
                info add;
                add.x1 = i;
                add.x2 = i+2;
                add.y1 = j;
                add.y2 = j+2;
                add.k = new_k;
                ans.pb(add);
                fore(r, i, i+3)
                    fore(c, j, j+3)
                        A[r][c] = (A[r][c]+new_k)%P[r][c];
            }

        }

    }
    for(int i=1;i<=n-7;i+=8){
        for(int j=1;j<=m;j+=1){
            int new_zeros,new_k,mx=0,zeros=0;
            fore(r, i, i+8)
                fore(c, j, j+1)
                    if(A[r][c]%P[r][c]==0)
                        zeros++;
            if(zeros < 5){
                mx = 0;
                forn(k, 610){
                    new_zeros = 0;
                    fore(r, i, i+8)
                        fore(c, j, j+1)
                            if( (A[r][c]+k)%P[r][c]==0)
                                new_zeros++;
                    if(new_zeros > mx){
                        mx = new_zeros;
                        new_k = k;
                    }
                }
            }

            if(mx>zeros+3){
                info add;
                add.x1 = i;
                add.x2 = i+7;
                add.y1 = j;
                add.y2 = j;
                add.k = new_k;
                ans.pb(add);
                fore(r, i, i+8)
                    fore(c, j, j+1)
                        A[r][c] = (A[r][c]+new_k)%P[r][c];
            }

        }

    }
    for(int i=1;i<=n;i+=1){
        for(int j=1;j<=m-7;j+=8){
            int new_zeros,new_k,mx=0,zeros=0;
            fore(r, i, i+1)
                fore(c, j, j+8)
                    if(A[r][c]%P[r][c]==0)
                        zeros++;
            if(zeros < 5){
                mx = 0;
                forn(k, 610){
                    new_zeros = 0;
                    fore(r, i, i+1)
                        fore(c, j, j+8)
                            if( (A[r][c]+k)%P[r][c]==0)
                                new_zeros++;
                    if(new_zeros > mx){
                        mx = new_zeros;
                        new_k = k;
                    }
                }
            }

            if(mx>zeros+3){
                info add;
                add.x1 = i;
                add.x2 = i;
                add.y1 = j;
                add.y2 = j+7;
                add.k = new_k;
                ans.pb(add);
                fore(r, i, i+1)
                    fore(c, j, j+8)
                        A[r][c] = (A[r][c]+new_k)%P[r][c];
            }

        }

    }
    for(int i=1;i<=n-5;i+=6){
        for(int j=1;j<=m;j+=1){
            int new_zeros,new_k,mx=0,zeros=0;
            fore(r, i, i+6)
                fore(c, j, j+1)
                    if(A[r][c]%P[r][c]==0)
                        zeros++;
            if(zeros < 3){
                mx = 0;
                forn(k, 610){
                    new_zeros = 0;
                    fore(r, i, i+6)
                        fore(c, j, j+1)
                            if( (A[r][c]+k)%P[r][c]==0)
                                new_zeros++;
                    if(new_zeros > mx){
                        mx = new_zeros;
                        new_k = k;
                    }
                }
            }

            if(mx>zeros+2){
                info add;
                add.x1 = i;
                add.x2 = i+5;
                add.y1 = j;
                add.y2 = j;
                add.k = new_k;
                ans.pb(add);
                fore(r, i, i+6)
                    fore(c, j, j+1)
                        A[r][c] = (A[r][c]+new_k)%P[r][c];
            }

        }

    }
    //1293
    for(int i=1;i<=n;i+=1){
        for(int j=1;j<=m-5;j+=6){
            int new_zeros, new_k,mx=0,zeros=0;
            fore(r,i,i+1)fore(c,j,j+6)if(A[r][c]%P[r][c]==0)zeros++;
            if(zeros<3){
                mx=0;
                forn(k,610){
                    new_zeros=0;
                    fore(r,i,i+1)fore(c,j,j+6)if((A[r][c]+k)%P[r][c]==0)new_zeros++;
                    if(new_zeros>mx){
                        mx=new_zeros;new_k=k;
                    }
                }
            }
            if(mx>zeros+2){
                info add;add.x1=i;add.x2=i;add.y1=j;add.y2=j+5;add.k=new_k;ans.pb(add);
                fore(r,i,i+1)fore(c,j,j+6)A[r][c]=(A[r][c]+new_k)%P[r][c];
            }
        }
    }
    for(int i=1;i<=n-2;i+=3){
        for(int j=1;j<=m-1;j+=2){
            int new_zeros,new_k,mx=0,zeros=0;
            fore(r,i,i+3)fore(c,j,j+2)if(A[r][c]%P[r][c]==0)zeros++;
            if(zeros<4){
                mx=0;
                forn(k,610){
                    new_zeros=0;
                    fore(r,i,i+3)fore(c,j,j+2)if((A[r][c]+k)%P[r][c]==0)
                                new_zeros++;
                    if(new_zeros>mx){
                        mx=new_zeros;new_k=k;
                    }
                }
            }
            if(mx>zeros){
                info add;add.x1=i;add.x2=i+2;add.y1=j;add.y2=j+1;add.k=new_k;ans.pb(add);
                fore(r,i,i+3)fore(c,j,j+2)A[r][c]=(A[r][c]+new_k)%P[r][c];
            }
        }
    }
    for(int i=1;i<=n-1;i+=2){
        for(int j=1;j<=m-2;j+=3){
            int new_zeros,new_k,zeros=0,mx=0;
            fore(r,i,i+2)fore(c,j,j+3)if(A[r][c]%P[r][c]==0)zeros++;
            if(zeros<4){
                mx=0;
                forn(k,610){
                    new_zeros=0;
                    fore(r,i,i+2)fore(c,j,j+3)if((A[r][c]+k)%P[r][c]==0)new_zeros++;
                    if(new_zeros>mx){
                        mx=new_zeros;new_k=k;
                    }
                }
            }
            if(mx>zeros){
                info add;add.x1=i;add.x2=i+1;add.y1=j;add.y2=j+2;add.k=new_k;ans.pb(add);
                fore(r,i,i+2)fore(c,j,j+3)A[r][c]=(A[r][c]+new_k)%P[r][c];
            }
        }
    }
    for(int i=1;i<=n-1;i+=2){
        for(int j=1;j<=m-1;j+=2){
            int new_zeros,new_k,mx=0,zeros=0;
            fore(r,i,i+2)fore(c,j,j+2)if(A[r][c]%P[r][c]==0)zeros++;
            if(zeros<3){
                mx=0;
                forn(k,610){
                    new_zeros=0;
                    fore(r,i,i+2)fore(c,j,j+2)if((A[r][c]+k)%P[r][c]==0)new_zeros++;
                    if(new_zeros>mx){
                        mx=new_zeros;new_k=k;
                    }
                }
            }
            if(mx>zeros){
                info add;add.x1=i;add.x2=i+1;add.y1=j;add.y2=j+1;add.k=new_k;
                ans.pb(add);
                fore(r,i,i+2)fore(c,j,j+2)A[r][c]=(A[r][c]+new_k)%P[r][c];
            }
        }
    }
    //1x6
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m-5;j+=6){
            int new_zeros,new_k,mx=0,zeros=0;
            fori(r,i,i)fori(c,j,j+5)if(A[r][c]%P[r][c]==0)zeros++;
            if(zeros<3){
                mx=0;
                forn(k,610){
                    new_zeros=0;
                    fori(r,i,i)fori(c,j,j+5)if((A[r][c]+k)%P[r][c]==0)new_zeros++;
                    if(new_zeros>mx){
                        mx=new_zeros;new_k=k;
                    }
                }
            }

            if(mx>zeros+1){
                info add;add.x1=i;add.x2=i;add.y1=j;add.y2=j+5;add.k=new_k;ans.pb(add);
                fori(r,i,i)fori(c,j,j+5)A[r][c]=(A[r][c]+new_k)%P[r][c];
            }
        }
    }
    //6x1
    for(int i=1;i<=n-5;i+=6){
        for(int j=1;j<=m;j++){
            int new_zeros,new_k,mx=0,zeros=0;
            fori(r,i,i+5)fori(c,j,j)if(A[r][c]%P[r][c]==0)zeros++;
            if(zeros<3){
                mx=0;
                forn(k,610){
                    new_zeros=0;
                    fori(r,i,i+5)fori(c,j,j)if((A[r][c]+k)%P[r][c]==0)new_zeros++;
                    if(new_zeros>mx){
                        mx=new_zeros;new_k=k;
                    }
                }
            }

            if(mx>zeros+1){
                info add;add.x1=i;add.x2=i+5;add.y1=j;add.y2=j;add.k=new_k;ans.pb(add);
                fori(r,i,i+5)fori(c,j,j)A[r][c]=(A[r][c]+new_k)%P[r][c];
            }
        }
    }

    for(int i=1;i<=n;i+=1){
        for(int j=1;j<=m-3;j+=4){
            int new_zeros,new_k,mx=0,zeros=0;
            fore(r,i,i+1)fore(c,j,j+4)if(A[r][c]%P[r][c]==0)zeros++;
            if(zeros<3){
                mx=0;
                forn(k,610){
                    new_zeros=0;
                    fore(r,i,i+1)fore(c,j,j+4)if((A[r][c]+k)%P[r][c]==0)new_zeros++;
                    if(new_zeros > mx){
                        mx = new_zeros;new_k = k;
                    }
                }
            }
            if(mx>zeros+2){
                info add;add.x1=i;add.x2=i;add.y1=j;add.y2=j+3;add.k=new_k;
                ans.pb(add);
                fore(r,i,i+1)fore(c,j,j+4)A[r][c]=(A[r][c]+new_k)%P[r][c];
            }
        }
    }
    for(int i=1;i<=n-3;i+=4){
        for(int j=1;j<=m;j++){
            int new_zeros,new_k,zeros=0,mx=0;
            fori(r,i,i+3)fori(c,j,j)if(A[r][c]%P[r][c]==0)zeros++;
            if(zeros<3){
                mx=0;
                forn(k,610){
                    new_zeros=0;
                    fori(r,i,i+3)fori(c,j,j)if((A[r][c]+k)%P[r][c]==0)new_zeros++;
                    if(new_zeros>mx){
                        mx=new_zeros;new_k=k;
                    }
                }
            }
            if(mx>zeros){
                info add;add.x1=i;add.x2=i+3;add.y1=j;add.y2=j;add.k=new_k;ans.pb(add);
                fori(r,i,i+3)fori(c,j,j)A[r][c]=(A[r][c]+new_k)%P[r][c];
            }
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m-1;j+=2){
            int new_zeros,new_k,mx=0,zeros=0;
            fori(r,i,i)fori(c,j,j+1)if(A[r][c]%P[r][c]==0)zeros++;
            if(zeros<3){
                mx=0;
                forn(k,610){
                    new_zeros=0;
                    fori(r,i,i)fori(c,j,j+1)if((A[r][c]+k)%P[r][c]==0)new_zeros++;
                    if(new_zeros>mx){
                        mx=new_zeros;new_k=k;
                    }
                }
            }

            if(mx>zeros){
                info add;add.x1=i;add.x2=i;add.y1=j;add.y2=j+1;add.k=new_k;ans.pb(add);
                fori(r,i,i)fori(c,j,j+1)A[r][c]=(A[r][c]+new_k)%P[r][c];
            }
        }
    }
    for(int i=1;i<=n-1;i+=2){
        for(int j=1;j<=m;j++){
            int new_zeros,new_k,mx=0,zeros=0;
            fori(r,i,i+1)fori(c,j,j)if(A[r][c]%P[r][c]==0)zeros++;
            if(zeros<3){
                mx=0;
                forn(k,610){
                    new_zeros=0;
                    fori(r,i,i+1)fori(c,j,j)if((A[r][c]+k)%P[r][c]==0)new_zeros++;
                    if(new_zeros>mx){
                        mx=new_zeros;new_k=k;
                    }
                }
            }

            if(mx>zeros){
                info add;add.x1=i;add.x2=i+1;add.y1=j;add.y2=j;add.k=new_k;ans.pb(add);
                fori(r,i,i+1)fori(c,j,j)A[r][c]=(A[r][c]+new_k)%P[r][c];
            }
        }
    }
    fori(i,1,n)fori(j,1,m)
        if(A[i][j]!=0){
            info f;
            f.x1=i;
            f.x2=i;
            f.y1=j;
            f.y2=j;
            f.k=P[i][j]-A[i][j];
            A[i][j]=(A[i][j]+f.k)%P[i][j];
            ans.pb(f);
        }
    int sz=ans.size();
    cout<<sz<<endl;
    forn(i, sz) cout<<ans[i].x1<<" "<<ans[i].y1<<" "<<ans[i].x2<<" "<<ans[i].y2<<" "<<ans[i].k<<endl;
    return 0;
}