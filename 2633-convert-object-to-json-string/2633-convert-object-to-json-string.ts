function jsonStringify(object: any): string {
  if (typeof object === 'string') {
    return '"' + object.replace(/"/g, '\\"') + '"';
  } else if (typeof object === 'number' || typeof object === 'boolean' || object === null) {
    return String(object);
  } else if (Array.isArray(object)) {
    const arr = [];
    for (let i = 0; i < object.length; i++) {
      arr.push(jsonStringify(object[i]));
    }
    return '[' + arr.join(',') + ']';
  } else if (typeof object === 'object') {
    const keys = Object.keys(object);
    const obj = [];
    for (let i = 0; i < keys.length; i++) {
      const key = keys[i];
      const value = jsonStringify(object[key]);
      obj.push('"' + key + '":' + value);
    }
    return '{' + obj.join(',') + '}';
  }
}