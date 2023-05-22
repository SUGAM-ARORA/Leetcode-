/**
 * @param {any} object
 * @return {string}
 */
var jsonStringify = function(object) {
  if (object === null) return 'null';
  if (typeof object === 'boolean' || typeof object === 'number') return object.toString();
  if (typeof object === 'string') return '"' + object.replace(/[\\"\n\r\t]/g, char => escapeMap[char]) + '"';
  if (Array.isArray(object)) return '[' + object.map(jsonStringify).join(',') + ']';
  if (typeof object === 'object') return '{' + Object.keys(object).map(key => jsonStringify(key) + ':' + jsonStringify(object[key])).join(',') + '}';
  return '';
};
