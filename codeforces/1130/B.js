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
    let nn = n << 1;
    let tierInHouse = lines[1].split(" ").map(tier => parseInt(tier));
    
    let availableTiers = new Array(nn);

    for (let i = 0; i < nn; ++i) {
        if (!availableTiers[tierInHouse[i]]) {
            availableTiers[tierInHouse[i]] = Array(2);
            availableTiers[tierInHouse[i]][0] = i;
        } else {
            availableTiers[tierInHouse[i]][1] = i;
        }
    }

    let currentPosition1 = 0;
    let currentPosition2 = 0;
    let distance = 0;
    let Abs = x => (x < 0) ? (-x) : x;
    for (let i = 1; i <= n; ++i) {
        
        distance += Abs(currentPosition1 - availableTiers[i][0]);
        distance += Abs(currentPosition2 - availableTiers[i][1]);
        currentPosition1 = availableTiers[i][0];
        currentPosition2 = availableTiers[i][1];
    }

    console.log(distance);

})();