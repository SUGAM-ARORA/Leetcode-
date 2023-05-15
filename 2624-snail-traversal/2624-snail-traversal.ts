declare global {
  interface Array<T> {
    snail(rowsCount: number, colsCount: number): number[][];
  }
}

Array.prototype.snail = function (rowsCount: number, colsCount: number): number[][] {
    if (rowsCount * colsCount != this.length) {
        return []
    }

    const result = (new Array(rowsCount)).fill([]).map(_ => (new Array(colsCount)).fill(0))

    let y = 0, x = 0, alt = 1
    this.forEach(v => {
        result[y][x] = v
        y += alt
        if (y === rowsCount || y === -1) {
            ++x
            alt = -alt
            y += alt
        }
    })
    return result
}

/**
 * const arr = [1,2,3,4];
 * arr.snail(1,4); // [[1,2,3,4]]
 */