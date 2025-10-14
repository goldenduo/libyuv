# Copyright 2025 The Chromium Authors. All rights reserved.
# Use of this source code is governed by a BSD-style license that can be
# found in the LICENSE file.

from recipe_engine.recipe_api import Property
from recipe_engine.config import ConfigGroup, Single

DEPS = [
    'recipe_engine/cipd',
    'recipe_engine/context',
    'recipe_engine/json',
    'recipe_engine/path',
    'recipe_engine/platform',
    'recipe_engine/step',
]
PROPERTIES = {
    '$libyuv/macos_sdk':
    Property(
        help='Properties specifically for the macos_sdk module.',
        param_name='sdk_properties',
        kind=ConfigGroup(
            sdk_version=Single(str),
            tool_pkg=Single(str),
            tool_ver=Single(str),
        ),
        default={
            # See https://xcodereleases.com/.
            'sdk_version':
            '16c5032a',  # Xcode 16.2
            'tool_package':
            'infra/tools/mac_toolchain/${platform}',
            'tool_version':
            'git_revision:29f9c476dd951c2dd7b0d43fa10ac2bd3f185787',
        },
    )
}
