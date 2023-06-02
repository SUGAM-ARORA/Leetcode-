/**
 * @return {Generator<number>}
 */
var fibGenerator = function*() {

  let current = 0; 
  let next = 1;

  while (true) {
    yield current; 

    [current, next] = [next, current + next];

    // The above line is equivalent to the following:
    // let temp = current;
    // current = next;
    // next = temp + next;
  }
};

/**
 * const gen = fibGenerator();
 * gen.next().value; // 0
 * gen.next().value; // 1
 */