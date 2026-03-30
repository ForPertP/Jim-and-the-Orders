'use strict';

import { WriteStream, createWriteStream } from "fs";
process.stdin.resume();
process.stdin.setEncoding('utf-8');

let inputString: string = '';
let inputLines: string[] = [];
let currentLine: number = 0;

process.stdin.on('data', function(inputStdin: string): void {
    inputString += inputStdin;
});

process.stdin.on('end', function(): void {
    inputLines = inputString.split('\n');
    inputString = '';

    main();
});

function readLine(): string {
    return inputLines[currentLine++];
}

/*
 * Complete the 'jimOrders' function below.
 *
 * The function is expected to return an INTEGER_ARRAY.
 * The function accepts 2D_INTEGER_ARRAY orders as parameter.
 */

function jimOrders(orders: number[][]): number[] {
    return orders
        .map((order, index) => [order[0] + order[1], index + 1])
        .sort((a, b) => a[0] - b[0] || a[1] - b[1])
        .map(item => item[1]);
}


function jimOrders2(orders: number[][]): number[] {
    const deliveryTimes = orders.map((order, index) => {
        const totalTime = order[0] + order[1];
        const orderId = index + 1;
        return [totalTime, orderId];
    });

    deliveryTimes.sort((a, b) => {
        if (a[0] !== b[0]) {
            return a[0] - b[0];
        }
        return a[1] - b[1];
    });

    return deliveryTimes.map(item => item[1]);
}


function main() {
    const ws: WriteStream = createWriteStream(process.env['OUTPUT_PATH']);

    const n: number = parseInt(readLine().trim(), 10);

    let orders: number[][] = Array(n);

    for (let i: number = 0; i < n; i++) {
        orders[i] = readLine().replace(/\s+$/g, '').split(' ').map(ordersTemp => parseInt(ordersTemp, 10));
    }

    const result: number[] = jimOrders(orders);

    ws.write(result.join(' ') + '\n');

    ws.end();
}
