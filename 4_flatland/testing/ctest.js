var fs = require('fs');

function disposizioniConRipetizione(elements, n) {
    let res = elements;
    for (let k = 1; k < n; k++) {
        let acc = [];
        for (let i = 0; i < res.length; i++) {
            for (let j = 0; j < elements.length; j++) {
                acc.push([...res[i], elements[j]]);
            }
        }
        res = acc;
    }
    return res;
}

const N = 12;
const inputData = [...Array(N).keys()].map((_, i) => i + 1).filter(v => v % 2 === 0).map(v => disposizioniConRipetizione(['>', '<'], v));
const parsedData = inputData.map(data => data.map(d => d.map((value, index) => ({ value, index }))));

function bruteForce(data) {

    if (data.length == 2) {
        return !(data[0].value === '<' && data[1].value === '>')
    }
    if (data.length < 2) {
        return false;
    }


    for (let i = 0; i < data.length; i++) {

        if (!(
            (i == 0 && data[i].value === '<') ||
            (i == data.length - 1 && data[i].value === '>')
        )) {

            if (data[i].value === '>') {
                if (bruteForce([...data.slice(0, i), ...data.slice(i + 2)]))
                    return true;
            } else {
                if (bruteForce([...data.slice(0, i - 1), ...data.slice(i + 1)]))
                    return true;
            }
        }
    }

    return false;
}

// parsedData[5].forEach((data, i) => {
//     let res = bruteForce(data)

//     console.log(
//         data.map(v => v.value).join(' '),
//         res ? " TRUE\t" : " FALSE\t"
//     );


// });


let aa = "";
parsedData[5].splice(parsedData[5].length / 2).forEach((data, i) => {
    let res = bruteForce(data)

    aa += res ? "1" : "0"

});

let bb = aa;
do {
    aa = bb;
    bb = aa.replace("010111010101110111111111010111", "\n------------------------------\n");
} while (aa != bb);

let toWrite = bb.split("\n").slice(1).filter(x => x[0] != '-').map(x => x.length - 2).join("\n")


fs.appendFile('data.txt', toWrite, function (err) {
    if (err) throw err;
    console.log("Done");
});











// let nuralObj = []

// for (let j = 0; j < parsedData.length; j++) {
//     console.log("J: ", parsedData[j].length);
//     let ex = 2*(j+1);

//     parsedData[j].forEach((data, i) => {

//         if (i % 1000 == 0)
//             console.log(i);

//         let res = bruteForce(data)

//         nuralObj.push({
//             input: [i, ex],
//             output: res ? 1 : 0
//         })

//     });
// }


// fs.appendFile('data.txt', JSON.stringify(nuralObj), function (err) {
//     if (err) throw err;
// });
// console.log('Saved!');
