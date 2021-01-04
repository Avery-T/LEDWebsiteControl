#!/usr/bin/env python3

import logging
import sys
logging.basicConfig(stream=sys.stderr)
sys.path.insert(0, '/var/www/LEDWebsiteControl/')
from LEDWebsiteControl import app as application

#insert your secret 
application.secret_key = ''
