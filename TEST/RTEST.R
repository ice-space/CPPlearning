n=3
K=0
a=c(1,2,3,
    4,5,6,
    7,8,9)
b=c(7,4,1,
    8,5,2,
    9,6,3)
c=c(9,8,7,6,5,4,3,2,1)
d=c(3,6,9,
    2,5,8,
    1,4,7)

A=matrix(a,n,byrow=TRUE)
B=matrix(b,n,byrow=TRUE)
c=matrix(c,n,byrow=TRUE)
D=matrix(d,n,byrow=TRUE)


while(k==0){
  while(A[1]!=B[1]){
    A=A+1
    B=B+1
    C=C+1
    D=D+1
    K=K+1
  }
}
K
