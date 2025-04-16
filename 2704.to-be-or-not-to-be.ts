type ToBeOrNotToBe = {
    toBe: (val: any) => boolean;
    notToBe: (val: any) => boolean;
};

function expect(val: any): ToBeOrNotToBe {
    const throwErr = (errStr) => { throw new Error(errStr) };
    return {
        toBe: (val2) => val2 === val || throwErr('Not Equal'),
        notToBe: (val2) => val2 !== val || throwErr('Equal')
    }
};

/**
 * expect(5).toBe(5); // true
 * expect(5).notToBe(5); // throws "Equal"
 */