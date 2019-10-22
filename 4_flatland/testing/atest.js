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

const N = 7;
const inputData = [...Array(N).keys()].map((_, i) => i + 1).filter(v => v % 2 !== 0).map(v => disposizioniConRipetizione(['>', '<'], v));
const parsedData = inputData.slice(1).map(data => data.map(d => d.map((value, index) => ({ value, index }))));

console.log(parsedData)

function bruteForce(data, result) {
    if (data.length == 1) {
        result.push(data[0]);
    }
    else {
        for (let i = 1; i < data.length - 1; i++) {
            switch (data[i].value) {
                case '>':
                    bruteForce([...data.slice(0, i), ...data.slice(i + 2)], result);
                    break;
                case '<':
                    bruteForce([...data.slice(0, i - 1), ...data.slice(i + 1)], result);
                    break;
            }
        }
    }
}

function fausto(data) {
    let result = [];
    if (data.length === 1) result.push(data[0]);
    else {
        for (let i = 0; i < data.length; i += 2) {
            if (i === 0 && data[i + 1].value === '>') result.push(data[i]);
            else if (i === data.length - 1 && data[i - 1].value === '<') result.push(data[i]);
            else if (i !== 0 && i !== data.length - 1 && data[i - 1].value === '<' && data[i + 1].value === '>') result.push(data[i]);
        }
    }
    return result;
}

/*
parsedData[2].forEach(data => {
    let rightSol = [];
    bruteForce(data, rightSol);
    rightSol = rightSol.map(v => v.index).filter((v, i, ar) => ar.indexOf(v) === i);
    let partialSol = fausto(data).map(v => v.index);
    const A = rightSol.sort((x, y) => x - y).join('');
    const B = partialSol.sort((x, y) => x - y).join('');

    console.log('Data ', data.map(v => v.value).join(' '));
    console.log('Right ', rightSol);
});
*/