//
//  selection_sort.h
//  objc-sorts
//
//  Created by Jesse Squires on 6/6/13.
//  Copyright (c) 2013 Hexed Bits. All rights reserved.
//

#import "sort_utils.h"

#ifndef objc_sorts_selection_sort_h
#define objc_sorts_selection_sort_h

void selection_sort(NSMutableArray *arr)
{
    NSUInteger minIndex = 0;
    for(NSUInteger i = 0; i < arr.count - 1; i++) {
        minIndex = i;
        
        for(NSUInteger j = i + 1; j < arr.count; j++) {
            if([[arr objectAtIndex:j] integerValue] < [[arr objectAtIndex:minIndex] integerValue])
                minIndex = j;
        }
        
        if(minIndex != i)
            [arr exchangeObjectAtIndex:i withObjectAtIndex:minIndex];
    }
}

void test_selection_sort(NSMutableArray *arr)
{
    NSLog(@"\n\nRunning selection sort...");
    NSDate *start = [NSDate date];
    selection_sort(arr);
    NSTimeInterval end = [start timeIntervalSinceNow] * -1;
    verfiySorted(arr);
    NSLog(@"Selection sort DONE: %lf", end);
}

#endif
