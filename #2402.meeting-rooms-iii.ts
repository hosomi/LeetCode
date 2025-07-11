function mostBooked(n: number, meetings: number[][]): number {
    meetings.sort((a, b) => a[0] - b[0]);
    let lastAvailable: number[] = new Array(n).fill(0);
    let roomUsedCount: number[] = new Array(n).fill(0);
    for (const [start, end] of meetings) {
        let found = false;
        let earlyEndRoom = 0;
        let earlyEndTime = Infinity;

        for (let room = 0; room < n; room++) {
            if (lastAvailable[room] <= start) {
                lastAvailable[room] = end;
                roomUsedCount[room]++;
                found = true;
                break;
            }

            if (lastAvailable[room] < earlyEndTime) {
                earlyEndTime = lastAvailable[room];
                earlyEndRoom = room;
            }
        }

        if (!found) {
            lastAvailable[earlyEndRoom] = earlyEndTime + (end - start); 
            roomUsedCount[earlyEndRoom]++;
        }
    }

    let resultRoom = 0;
    for (let room = 1; room < n; room++) {
        if (roomUsedCount[room] > roomUsedCount[resultRoom]) {
            resultRoom = room;
        }
    }

    return resultRoom;
};
