var countTrapezoids = function (points) {
    const n = points.length;
    const inf = 1e9 + 7;

    // slope → list of intercepts for all lines formed by pairs of points
    // (Same slope + different intercept = parallel lines)
    const slopeToIntercept = new Map();

    // midpoint → list of slopes for all segments sharing that midpoint
    // (If two segments share midpoint + have same slope = same line counted twice)
    const midToSlope = new Map();

    let ans = 0;

    // Generate all possible lines from pairs of points
    for (let i = 0; i < n; i++) {
        const [x1, y1] = points[i];
        for (let j = i + 1; j < n; j++) {
            const [x2, y2] = points[j];

            // Differences
            const dx = x1 - x2;
            const dy = y1 - y2;

            let k, b;

            // Handle vertical line (infinite slope)
            if (x2 === x1) {
                k = inf;       // special slope
                b = x1;        // x = constant
            } else {
                // slope
                k = (y2 - y1) / (x2 - x1);

                // y-intercept (derived to avoid precision issues)
                b = (y1 * dx - x1 * dy) / dx;
            }

            // Unique key for midpoint of segment
            const mid = (x1 + x2) * 10000 + (y1 + y2);

            // Store the intercept for this slope
            if (!slopeToIntercept.has(k)) slopeToIntercept.set(k, []);
            slopeToIntercept.get(k).push(b);

            // Store the slope for this midpoint
            if (!midToSlope.has(mid)) midToSlope.set(mid, []);
            midToSlope.get(mid).push(k);
        }
    }

    // -------- STEP 1: COUNT ALL PAIRS OF PARALLEL LINES ----------
    // Any two parallel lines (same slope, different intercepts)
    // can act as the LEFT and RIGHT sides of a trapezoid.
    for (const sti of slopeToIntercept.values()) {
        if (sti.length === 1) continue;

        const cnt = new Map();

        // Count how many times each intercept occurs
        for (const bVal of sti) {
            cnt.set(bVal, (cnt.get(bVal) || 0) + 1);
        }

        // Count combinations: total pairs = sum over intercept groups
        let totalSum = 0;
        for (const count of cnt.values()) {
            // For each group, pair it with all previous groups
            ans += totalSum * count;
            totalSum += count;
        }
    }

    // -------- STEP 2: SUBTRACT OVERCOUNTED PAIRS ----------
    // If two segments lie on the exact same line (same midpoint + same slope),
    // they were counted above but shouldn't form trapezoids.
    for (const mts of midToSlope.values()) {
        if (mts.length === 1) continue;

        const cnt = new Map();

        // Count slopes that appear multiple times from same midpoint
        for (const kVal of mts) {
            cnt.set(kVal, (cnt.get(kVal) || 0) + 1);
        }

        // Subtract these invalid duplicates
        let totalSum = 0;
        for (const count of cnt.values()) {
            ans -= totalSum * count;
            totalSum += count;
        }
    }

    return ans;
};