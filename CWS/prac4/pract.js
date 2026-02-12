// arrow operator

let a = (n1,n2)=>n1*n2

console.log(a(5,6))


const sayHello = () => console.log("Hello")


sayHello()

let arr = [45,24,22]

let b = arr.map((value) => {
    return value + 1
})
console.log(b)
