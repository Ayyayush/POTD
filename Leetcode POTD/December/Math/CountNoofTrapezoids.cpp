class Solution {
    fun countTrapezoids(coordinatePoints: Array<IntArray>): Int {
        val MODULO_CONSTANT = 1_000_000_007L
        val INVERSE_OF_2 = 500_000_004L // modular inverse of 2 under MOD

        // Map to count how many points lie on each horizontal y-level
        val yCoordinateFrequencyMap = HashMap<Int, Long>()
        for ((xCoordinate, yCoordinate) in coordinatePoints) {
            yCoordinateFrequencyMap[yCoordinate] =
                yCoordinateFrequencyMap.getOrDefault(yCoordinate, 0L) + 1
        }

        // Count how many horizontal segments can be formed from each y-level
        val horizontalSegmentList = ArrayList<Long>()
        var totalHorizontalSegments = 0L

        for (pointCountAtY in yCoordinateFrequencyMap.values) {
            if (pointCountAtY >= 2) {
                val segmentsOnSameYLine = (pointCountAtY * (pointCountAtY - 1) / 2) % MODULO_CONSTANT
                horizontalSegmentList += segmentsOnSameYLine
                totalHorizontalSegments = (totalHorizontalSegments + segmentsOnSameYLine) % MODULO_CONSTANT
            }
        }

        // Compute total trapezoid combinations = (S² - Σ(Sᵢ²)) / 2
        var sumOfSquaredSegmentCounts = 0L
        for (individualSegmentCount in horizontalSegmentList) {
            sumOfSquaredSegmentCounts =
                (sumOfSquaredSegmentCounts + individualSegmentCount * individualSegmentCount) % MODULO_CONSTANT
        }

        val totalTrapezoidPairs = (
            (totalHorizontalSegments * totalHorizontalSegments % MODULO_CONSTANT -
             sumOfSquaredSegmentCounts + MODULO_CONSTANT) % MODULO_CONSTANT * INVERSE_OF_2
        ) % MODULO_CONSTANT

        return totalTrapezoidPairs.toInt()
    }
}
