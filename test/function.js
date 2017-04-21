'use strict';
const buildType = process.config.target_defaults.default_configuration;
const binding = require(`./build/${buildType}/binding.node`);
const assert = require('assert');

let obj = {};
assert.deepStrictEqual(binding.function.voidCallback(obj), undefined);
assert.deepStrictEqual(obj, { "foo": "bar" });

assert.deepStrictEqual(binding.function.valueCallback(), { "foo": "bar" });

let args = null;
let ret = null;
let receiver = null;
function testFunction() {
   receiver = this;
   args = [].slice.call(arguments);
   return ret;
}
function testConstructor() {
   args = [].slice.call(arguments);
}

ret = 4;
assert.equal(binding.function.callWithArgs(testFunction, 1, 2, 3), 4);
assert.strictEqual(receiver, undefined);
assert.deepStrictEqual(args, [ 1, 2, 3 ]);

ret = 5;
assert.equal(binding.function.callWithVector(testFunction, 2, 3, 4), 5);
assert.strictEqual(receiver, undefined);
assert.deepStrictEqual(args, [ 2, 3, 4 ]);

ret = 6;
assert.equal(binding.function.callWithReceiverAndArgs(testFunction, obj, 3, 4, 5), 6);
assert.deepStrictEqual(receiver, obj);
assert.deepStrictEqual(args, [ 3, 4, 5 ]);

ret = 7;
assert.equal(binding.function.callWithReceiverAndVector(testFunction, obj, 4, 5, 6), 7);
assert.deepStrictEqual(receiver, obj);
assert.deepStrictEqual(args, [ 4, 5, 6 ]);

obj = binding.function.callConstructorWithArgs(testConstructor, 5, 6, 7);
assert(obj instanceof testConstructor);
assert.deepStrictEqual(args, [ 5, 6, 7 ]);

obj = binding.function.callConstructorWithVector(testConstructor, 6, 7, 8);
assert(obj instanceof testConstructor);
assert.deepStrictEqual(args, [ 6, 7, 8 ]);

assert.equal(binding.function.voidCallback.name, 'voidCallback');
assert.equal(binding.function.valueCallback.name, 'valueCallback');

// TODO: Function::MakeCallback tests