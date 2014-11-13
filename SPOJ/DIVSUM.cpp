#include <bits/stdc++.h>
#include <unistd.h>
using namespace std;
class FastInput 
{
public:
  char buffer[32768];unsigned int data[16384]; unsigned int dataOffset, dataSize;unsigned int v;
public:
  FastInput()
  {dataOffset=0;dataSize=0;v=0x80000000;}
  unsigned int ReadNext()
    {if (dataOffset==dataSize){
      int r=read(0,buffer,sizeof(buffer));if(r<=0)return v;dataOffset=0;dataSize=0;int i=0;
      if (buffer[0] < '0')
        {if ( v!= 0x80000000){data[dataSize++] = v;v = 0x80000000;}for (; (i < r) && (buffer[i] < '0'); ++i);}
      for (; i < r;){if (buffer[i] >= '0'){v = v * 10 + buffer[i] - 48;++i;}else{data[dataSize++] = v;v = 0x80000000;for (i = i + 1; (i < r) && (buffer[i] < '0'); ++i);}}}return data[dataOffset++];}};
class FastOutput 
{     
    public:
    char data[32768];
    unsigned int dataOffset;
    public:
    FastOutput() 
    {dataOffset=0;}
    ~FastOutput(){}
    void Flush(){if(dataOffset){if(write(1, data, dataOffset));dataOffset = 0;}}
    void PrintUint(unsigned int v, char d) 
    {if(dataOffset+11>sizeof(data))Flush();
    if(v<100000){if(v<1000){if(v<10){data[dataOffset + 0]=v+48;dataOffset+=1;}else if(v<100){data[dataOffset+1]=v-v/10*10+48;v/=10;data[dataOffset+0]=v+48;dataOffset+=2;}
    else{data[dataOffset+2]=v-v/10*10+48;v/=10;data[dataOffset + 1]=v-v/10*10+48;v/=10;data[dataOffset+0]=v+48;dataOffset+=3;}}else{
    if(v<10000){data[dataOffset + 3]=v-v/10*10+48;v/=10;data[dataOffset+2]=v-v/10*10+48;v/=10;data[dataOffset+1]=v-v / 10 * 10 + 48; v/=10;
data[dataOffset+0]=v+48;
dataOffset+=4;
}else{
data[dataOffset+4]=v-v/10*10+48;v/=10;
data[dataOffset+3]=v-v/10*10+48;v/=10;
data[dataOffset+2]=v-v/10*10+48;v/=10;
data[dataOffset+1]=v-v/10*10+48;v/=10;
data[dataOffset+0]=v+48;
dataOffset+=5;
}
}

}else{
if(v<100000000){
if(v<1000000){
data[dataOffset+5]=v-v/10*10+48;v/=10;
data[dataOffset+4]=v-v/10*10+48;v/=10;
data[dataOffset+3]=v-v/10*10+48;v/=10;
data[dataOffset+2]=v-v/10*10+48;v/=10;
data[dataOffset+1]=v-v/10*10+48;v/=10;
data[dataOffset+0]=v+48;
dataOffset+=6;
}else if (v<10000000){
data[dataOffset+6]=v-v/10*10+48;v/=10;
data[dataOffset+5]=v-v/10*10+48;v/=10;
data[dataOffset+4]=v-v/10*10+48;v/=10;
data[dataOffset+3]=v-v/10*10+48;v/=10;
data[dataOffset+2]=v-v/10*10+48;v/=10;
data[dataOffset+1]=v-v/10*10+48;v/=10;
data[dataOffset+0]=v+48;
dataOffset+=7;
}else{
data[dataOffset + 7] = v - v / 10 * 10 + 48; v /= 10;
    data[dataOffset + 6] = v - v / 10 * 10 + 48; v /= 10;
    data[dataOffset + 5] = v - v / 10 * 10 + 48; v /= 10;
    data[dataOffset + 4] = v - v / 10 * 10 + 48; v /= 10;
    data[dataOffset + 3] = v - v / 10 * 10 + 48; v /= 10;
    data[dataOffset + 2] = v - v / 10 * 10 + 48; v /= 10;
    data[dataOffset + 1] = v - v / 10 * 10 + 48; v /= 10;
    data[dataOffset + 0] = v + 48;
    dataOffset += 8;
    }
    } else {
    if (v < 1000000000) {
    data[dataOffset + 8] = v - v / 10 * 10 + 48; v /= 10;
    data[dataOffset + 7] = v - v / 10 * 10 + 48; v /= 10;
    data[dataOffset + 6] = v - v / 10 * 10 + 48; v /= 10;
    data[dataOffset + 5] = v - v / 10 * 10 + 48; v /= 10;
    data[dataOffset + 4] = v - v / 10 * 10 + 48; v /= 10;
    data[dataOffset + 3] = v - v / 10 * 10 + 48; v /= 10;
    data[dataOffset + 2] = v - v / 10 * 10 + 48; v /= 10;
    data[dataOffset + 1] = v - v / 10 * 10 + 48; v /= 10;
    data[dataOffset + 0] = v + 48;
    dataOffset += 9;
    } else {
    data[dataOffset + 9] = v - v / 10 * 10 + 48; v /= 10;
    data[dataOffset + 8] = v - v / 10 * 10 + 48; v /= 10;
    data[dataOffset + 7] = v - v / 10 * 10 + 48; v /= 10;
    data[dataOffset + 6] = v - v / 10 * 10 + 48; v /= 10;
    data[dataOffset + 5] = v - v / 10 * 10 + 48; v /= 10;
    data[dataOffset + 4] = v - v / 10 * 10 + 48; v /= 10;
    data[dataOffset + 3] = v - v / 10 * 10 + 48; v /= 10;
    data[dataOffset + 2] = v - v / 10 * 10 + 48; v /= 10;
    data[dataOffset + 1] = v - v / 10 * 10 + 48; v /= 10;
    data[dataOffset + 0] = v + 48;
    dataOffset += 10;
    }
    }
    }
    data[dataOffset++] = d;
    }
    void PrintChar(char d){if (dataOffset+1>sizeof(data)) Flush();data[dataOffset++] = d;}
    void ReplaceChar(int offset, char d){data[dataOffset + offset] = d;}
};

FastInput g_fi;
FastOutput g_fo;
int main() 
{
  unsigned int n;
  unsigned int N = g_fi.ReadNext();
  while(N--){
    n = g_fi.ReadNext();
    unsigned int ans = 1;
    if(n==1)
      ans = 0;
    bool taken[n];
    memset(taken, false, sizeof(taken));
    taken[1] = true;
    for(int i=2;i<=sqrt(n);i++){
      if(n%i==0 && taken[i]==false){
        ans += i;
        taken[i] = true;
        if(taken[n/i]==false){
          ans += (n/i);
          taken[n/i] = true;
        }
      }
    }
    g_fo.PrintUint(ans, '\n');
  }
  g_fo.Flush();
  return 0;
}