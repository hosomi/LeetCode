function removeSubfolders(folder: string[]): string[] {
    if (folder.length < 2) {
        return folder;
    }
    
    folder.sort();

    const result: string[] = [];
    let i = 0, j = 1;
    while (i < folder.length) {
        if (j >= folder.length) {
            result.push(folder[i]);
            break;
        }

        if (folder[j].startsWith(folder[i]) && folder[j][folder[i].length] === "/") {
            j++;
        } else {
            result.push(folder[i]);
            i = j;
            j++;
        }
    }
    return result;
};
