function throttle(fn, t) {
  let timerId;
  let lastArgs;

  return function wrapper(...args) {
    if (!timerId) {
      fn(...args);
      timerId = setTimeout(() => {
        timerId = null;
        if (lastArgs) {
          wrapper(...lastArgs);
          lastArgs = null;
        }
      }, t);
    } else {
      lastArgs = args;
    }
  };
}
/**
 * const throttled = throttle(console.log, 100);
 * throttled("log"); // logged immediately.
 * throttled("log"); // logged at t=100ms.
 */