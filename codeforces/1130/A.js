let rawInput = '';
process.stdin.on('data', c => rawInput += c);
let inputByLinesOnResolve = new Promise((resolve, reject) => {
    process.stdin.on('end', () => {
        const { EOL } = require('os');
        resolve(rawInput.split(EOL));
    });
});

(async function(){

    let lines = await inputByLinesOnResolve;
    let n = parseInt(lines[0]);
    let items = lines[1].split(" ");
    let ls = parseFloat(n) / 2.0;
    let found = 0;

    for (let d = -1000; d <= 1000; ++d) {
        if (!d) { continue; }
        let many = 0;
        for (let i = 0; i < n; ++i) {
            let curd = parseFloat(items[i]) / parseFloat(d);
            if (curd > 0) { many++; }
        }
        if (many < ls) { continue; }
        found = 1;
        console.log(d);
        break;
    }
    if (!found) { console.log(0); }

})();