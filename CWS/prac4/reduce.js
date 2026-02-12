let arr=[1,2,3,5,2,1]

const reduce_func = (h1,h2) => {
    return h1+h2
}

let a3=arr.reduce(reduce_func)
console.log(a3)

const sum = [1,2,3,5,2,1].reduce((a,b) => a + b)

const sum1 = arr.reduce((acc, val) => acc + val,0)

const max = arr.reduce((a,b) => a > b ? a:b)
console.log(max)
