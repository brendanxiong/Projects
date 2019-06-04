//
//  ViewController.swift
//  firstiOSApp
//
//  Created by CLICC User on 1/16/19.
//  Copyright © 2019 CLICC User. All rights reserved.
//

import UIKit

class ViewController: UIViewController {
    var score = 0
    var timer: Timer!
    
    override func viewDidLoad() {
        super.viewDidLoad()
        // Do any additional setup after loading the view, typically from a nib.
    }

    override func didReceiveMemoryWarning() {
        super.didReceiveMemoryWarning()
        // Dispose of any resources that can be recreated.
    }

//put this sinisde tappedTapButton
    score += 1
    scoreLabel.text = String(score)
    
}
//inside tappedStartBUtton
time = 10
//copy timelabel.text stuff

//after time label

if time < = 0{
 time.invalidate()
    timeLabel.text = "0.00"
    
    startButton.isEnabled = true
}
}
