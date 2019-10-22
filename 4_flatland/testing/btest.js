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

const N = 14;
const inputData = [...Array(N).keys()].map((_, i) => i + 1).filter(v => v % 2 === 0).map(v => disposizioniConRipetizione(['>', '<'], v));
const parsedData = inputData.map(data => data.map(d => d.map((value, index) => ({ value, index }))));

function bruteForce(data) {
    if (data.length == 2) {
        return (data[1].value !== '>')
    }


    for (let i = 1; i < data.length; i++) {

        if (data[i].value === '>') {
            if (i !== data.length - 1)
                if (bruteForce([...data.slice(0, i), ...data.slice(i + 2)]))
                    return true;
        } else {
            if (bruteForce([...data.slice(0, i - 1), ...data.slice(i + 1)]))
                return true;
        }

    }

    return false;
}

function calc(n, callback) {

    parsedData[n].forEach((data, i) => {
        if (i % 2) {
            return;
        }

        let res = bruteForce(data)
        callback(res, data);
    });

}

function printAll(n) {

    calc(n, (res, data) => {
        console.log(
            data.map(v => v.value).join(' '),
            res ? " TRUE\t" : " FALSE\t"
        );
    })

}

function toCSV(n) {
    let aa = "";
    calc(n, (res, data) => {
        aa += data.map((v, i) => (i == 0 || i == data.length - 1) ? '_' : (v.value == '<' ? '1' : '0')).join('') + '\t' + (res ? "TRUE" : "FALSE") + "\n";
    })

    fs.writeFileSync('dataCSV' + n + '.tsv', aa);
}

function toCSV10(n) {
    let aa = "";
    calc(n, (res, data) => {
        let tem = data.map((v, i) => (false && (i == 0 || i == data.length - 1)) ? '_' : (v.value == '<' ? '1' : '0')).join('')

        let has10 = false;
        for (let i = 1; i <= tem.length - 1; i += 2) {
            if (tem[i] === '1' && tem[i + 1] === '0')
                has10 = true;

        }


        aa += tem
            + '\t'
            + (res ? "TRUE" : "FALSE")
            + "\t"
            + (has10 ? "TRUE" : "FALSE")
            + "\n";
    })

    fs.writeFileSync('dataCSV' + n + '.tsv', aa);
}

function onlyResult(n) {

    let aa = "";
    let bb = "";
    calc(n, res => {
        aa += res ? "TRUE\n" : "FAUSTO\n"
        bb += res ? "1" : "0"
    })



    let b = bb;
    do {
        bb = b;
        b = bb.replace("010111010101110111111111010111", "\n------------------------------\n");
    } while (bb != b);

    bb = bb.split("\n").filter((e, i) => i % 2 == 0)

    bb.forEach(x => {
        if (x.length > 0 && [...x].splice(1).indexOf('0') != -1)
            console.log("KO", x);

    });

    bb = bb.map(x => x.length - 2).splice(1).join("\n");

    fs.writeFileSync('data' + n + '.txt', bb);
}

printAll(1);
toCSV10(1);
toCSV10(2);
toCSV10(3);
toCSV10(4);
toCSV10(5);








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
