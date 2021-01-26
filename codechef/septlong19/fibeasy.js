let fib = [0, 1];
//actual fibonacci number
//0,1 0, +1
//5,1 10^7, +1
//5,6 2*10^7, +1
//0,1 3*10^7, +1
//5,1 4*10^7, +1
//repeats
for (let i = 2; i <= 70000000; i++) {
	fib[i] = (fib[i - 1] + fib[i - 2]) % 10;
}
for(let i=0;i<10;i++)
{
    console.log(i, fib[i]);
}
for(let i=60;i<70;i++)
{
    console.log(i, fib[i]);
}
// for(let i=0;i<100;i++)
// {
//     console.log(i,': ',fib[i])
// }
// let x = 0;
// // let n = 60000000;
// let n = 1000000000000000000;
// n -= x;
// // console.log(fib[n]);
// console.log(Math.pow(2, Math.trunc(Math.log2(n+x))));
// console.log(Math.pow(2, Math.trunc(Math.log2(n+x)) + 1));
// console.log(fib[Math.pow(2, Math.trunc(Math.log2(n))) - 1]);
