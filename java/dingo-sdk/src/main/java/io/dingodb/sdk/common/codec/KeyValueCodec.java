/*
 * Copyright 2021 DataCanvas
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

package io.dingodb.sdk.common.codec;

import io.dingodb.sdk.common.KeyValue;
import org.checkerframework.checker.nullness.qual.NonNull;

public interface KeyValueCodec {
    Object[] decode(KeyValue keyValue);

    Object[] decodeKeyPrefix(byte[] keyPrefix);

    KeyValue encode(Object @NonNull [] record);

    byte[] encodeKey(Object[] record);

    default byte[] encodeKeyPrefix(Object[] record) {
        return encodeKeyPrefix(record, record.length);
    }

    byte[] encodeKeyPrefix(Object[] record, int columnCount);

    byte[] encodeMinKeyPrefix();

    byte[] encodeMaxKeyPrefix();

    byte[] resetPrefix(byte[] key, long prefix);
}
