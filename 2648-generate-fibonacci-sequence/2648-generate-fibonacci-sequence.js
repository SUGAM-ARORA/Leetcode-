/**
 * @return {Generator<number>}
 */
var fibGenerator = function*() {
    for(let a=0, b=1; 
        true ;
       b+=a , a=b-a)
        yield a;
};

/**
 * const gen = fibGenerator();
 * gen.next().value; // 0
 * gen.next().value; // 1
 */