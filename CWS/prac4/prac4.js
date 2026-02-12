const functionName=(param1,param2)=>{
    return param1+param2;
}
//1.Single parameter
const square=num=>num*num;
console.log(square(5));

//2.Multiple parameters
const sum=(x,y)=>x+y;
console.log(sum(4,6));

//3.No parameters
const message=()=>"Hello, World!";
console.log(message());

//4.Multiple statements
const subtract=(x,y)=>{
    const result=x-y;
    return result;  
}
// basic map - add 1 to each element
const numbers=[45,23,21];
